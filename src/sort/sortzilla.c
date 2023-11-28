/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/28 13:47:32 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(t_lydt *lydt, int layer, size_t fs)
{
	lydt->low = (layer * 2) * (fs / LAYERZILLA);
	lydt->top = ((layer + 1) * 2) * (fs / LAYERZILLA);
	printf("Top: %lu\tLow: %lu\t\t",lydt->top , lydt->low);
	fflush(NULL);
}

static void	rotate_opti_asf(t_llint *a, t_llint *b, size_t tl, size_t *loop_count, size_t start_a_size)
{
	if (a->head && a->head->index > tl && *loop_count < start_a_size) /* OPTIMIZE SHIT*/
	{
		rotate_rotate(a, b);
		(*loop_count)++;
	}
	else
		rotate_b(b);
}

/*
PUSH TO B WITH LAYERING
*/
void	zilla_layering(t_llint *a, t_llint *b, size_t og_size)
{
	t_nodeint	*node;
	t_lydt		lydt;
	int			layer;
	size_t 		loop_count;
	size_t		start_a_size;

	layer = 0;
	while (layer < (LAYERZILLA / 2))
	{
		loop_count = 0;
		node = a->head;
		start_a_size = a->size;
		if (!node)
			printf("WTFFFFFFFF\n");
		zilla_get_layers(&lydt, layer, og_size);
		while (node && loop_count++ < start_a_size)
		{
			if (node->index >= lydt.low && node->index < lydt.top) /*IF IN THE LAYERS, THEN PUSH*/
			{
				node = push_b(a, b);
				if (!node)
				{
					printf("push_b NODE = NULL AAA\n");
					break ;
				}
				if (node->index < (size_t)lydt_mid(&lydt)) /*ROTATE IF should go under the stack B*/
					rotate_opti_asf(a, b, lydt.top, &loop_count, start_a_size);
			}
			else
				rotate_a(a);
			node = a->head;
		}
		layer++;
	}
	printf("LAYERING DONE\n");
}

/*
Find a way to push INDEX onto A while optimizing rotates
	Push half the thing over it to A, the rr until INDEX
	PUSH INDEX
*/
void	zilla_phaseb(t_llint *stack_a, t_llint *stack_b, size_t og_size)
{
	t_lydt	lydt;
	int		layer;

	layer = 0;
	while (layer < LAYERZILLA)
	{
		if (layer % 2 == 0)
		{
			lydt.low = layer * (og_size / LAYERZILLA);
			lydt.top = (layer + 1) * (og_size / LAYERZILLA);
		}
		else
		{
			lydt.low = (LAYERZILLA - layer - 1) * (og_size / LAYERZILLA);
			lydt.top = (LAYERZILLA - layer) * (og_size / LAYERZILLA);
		}
		zillasort_layer(stack_a, stack_b, &lydt);
		layer++;
	}
}

void	sortzilla(t_llint *a, t_llint *b)
{
	size_t		og_size;

	if (!a || !b)
		return ;
	give_indexes(a);
	og_size = a->size;
			printf("\n\t---\t--- A ---\t---\n\n");
			ft_llint_printm(a);
	printf("Stack A size: %ld\tMath: %ld\n\n", a->size, a->size / 6);
	zilla_layering(a, b, og_size); /* PUSH A TO B within layers (6 groups) */
	//zilla_phaseb(stack_a, stack_b, og_size); /* PUSH BACK INTO A and sorts it*/
	ft_printf("SORTZILLA DONE\n\n");
			printf("\n\t---\t--- A ---\t---\n\n");
			ft_llint_printm(a);
			printf("\n\t---\t--- B ---\t---\n\n");
			ft_llint_printm(b);
}
