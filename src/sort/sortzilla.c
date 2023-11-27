/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 20:05:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(t_lydt *lydt, int layer, size_t fs)
{
	lydt->low = layer * 2 * (fs / LAYERZILLA);
	lydt->top = (layer + 1) * 2 * (fs / LAYERZILLA);
	printf("Top: %lu\tLow: %lu\n",lydt->top , lydt->low);
	fflush(NULL);
}

static void	rotate_opti_asf(t_llint *a, t_llint *b, t_nodeint *node, size_t tl)
{
	if (node->next && node->next->index > tl) /* OPTIMIZE SHIT*/
		rotate_rotate(a, b);
	else
		rotate_a(a);
}

/*
PUSH TO B WITH LAYERING
*/
void	zilla_layering(t_llint *a, t_llint *b, size_t og_size)
{
	t_nodeint	*node;
	t_lydt		lydt;
	int			layer;
	int magicalshit=0;
	
	layer = 0;
	while (layer < (LAYERZILLA / 2))
	{
		zilla_get_layers(&lydt, layer, og_size);
		node = a->head;
		while (node && a->size > 1)
		{
			if (node->index >= lydt.low && node->index < lydt.top) /*IF IN THE LAYERS, THEN PUSH*/
			{
				printf("mgs:%d\n", magicalshit);
				fflush(NULL);
				push_b(a, b);
				if (node->index > (lydt.top - lydt.low) / 2) /*ROTATE IF ON SMALL SIDE*/
					rotate_opti_asf(a, b, node, lydt.top);
			}
			else
				rotate_a(a);
			node = node->next;
		}
		layer++;
	}
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

void	sortzilla(t_llint *stack_a, t_llint *stack_b)
{
	size_t		og_size;

	if (!stack_a || !stack_b)
		return ;
	give_indexes(stack_a);
	og_size = stack_a->size;
	printf("Stack A size: %ld\tMath: %d\n", stack_a->size, 100 / 6);
	zilla_layering(stack_a, stack_b, og_size); /* PUSH A TO B within layers (6 groups) */
	zilla_phaseb(stack_a, stack_b, og_size); /* PUSH BACK INTO A and sorts it*/
	ft_printf("SORTZILLA DONE\n\n");
	ft_printf("STACK A\n");
	ft_llint_print(stack_a);
}
