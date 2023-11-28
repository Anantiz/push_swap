/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/28 19:45:11 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(t_lydt *lydt, size_t layer)
{
	layer *= 2;
	lydt->low = layer * (lydt->og_size / lydt->layerzilla);
	layer += 2;
	lydt->top = layer* (lydt->og_size / lydt->layerzilla);
	if (layer == lydt->layerzilla)
		lydt->top = lydt->og_size;
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
int	zilla_layering(t_llint *a, t_llint *b, t_lydt *lydt)
{
	t_nodeint	*node;
	size_t		layer;
	size_t 		loop_count;
	size_t		start_a_size;

	layer = 0;
	while (layer < (lydt->layerzilla / 2))
	{
		loop_count = 0;
		node = a->head;
		start_a_size = a->size;
		zilla_get_layers(lydt, layer);
		while (loop_count++ < start_a_size)
		{
			if (node->index >= lydt->low && node->index < lydt->top) /*IF IN THE LAYERS, THEN PUSH*/
			{
				node = push_b(a, b);
				if (!node)
					return (-1) ;
				if (node->index < (size_t)lydt_mid(lydt)) /*ROTATE IF should go under the stack B*/
					rotate_opti_asf(a, b, lydt->top, &loop_count, start_a_size);
			}
			else
				rotate_a(a);
			node = a->head;
		}
		layer++;
	}
	FILE *fd = fopen("log.txt", "w");
	fprintf(fd, "LAYERING %lu: count=%lu\n",layer, op_mgcount);
	fclose(fd);
	return (0);
}

/*
Currently, we want to send one layer at a time, in reverse order,
so first last layer, then second to last layer
*/
void	zilla_phaseb(t_llint *a, t_llint *b, t_lydt	*lydt)
{
	int		layer;

	layer = lydt->layerzilla;
	if (a->head == NULL)
		zilla_move_node(a ,b , lydt->og_size - 1);
	if (a->size != 1)
	{
		printf("AAAAA.size= %lu\n", a->size);
		return ;
	}
	// printf("ASDSADASDASD\n");
	// ft_llint_printm(a);
	// ft_llint_printm(b);
	// exit(0);
	while (layer)
	{
		lydt->low = (layer - 1) * (lydt->og_size / lydt->layerzilla);
		lydt->top = (layer) * (lydt->og_size / lydt->layerzilla);
		if (layer == LAYERZILLA)
			lydt->top = lydt->og_size;
		zillasort_layer(a, b, lydt);
		FILE *fd = fopen("log.txt", "a");
		fprintf(fd, "Layer % d: low=%lu\ttop=%lu\tcount=%lu\n",layer,lydt->low, lydt->top ,op_mgcount);
		fclose(fd);
		layer--;
	}
}

int	sortzilla(t_llint *a, t_llint *b)
{
	t_lydt		lydt;

	if (!a || !b)
		return (1);
	if (check_sort(a) == -1)
		return (0);
	give_indexes(a);
	lydt.og_size = a->size;
	if (a->size <= 110)
		lydt.layerzilla = LAYERZILLA_SMALL;
	else
		lydt.layerzilla = LAYERZILLA;
	if (zilla_layering(a, b, &lydt))
		return (-1);	
	zilla_phaseb(a, b, &lydt);
	return (0);
}
