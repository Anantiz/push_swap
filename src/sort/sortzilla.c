/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 18:12:57 by aurban           ###   ########.fr       */
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

static void	rotate_opti_asf(t_llint *a, t_llint *b, t_lydt *lydt, size_t *loop_count, size_t start_a_size)
{
	if ((a->head && a->head->index > lydt->top && *loop_count < start_a_size) ||
	(a->head->index == lydt->og_size - 1 || a->head->index == lydt->og_size - 2 || a->head->index == lydt->og_size - 3 || a->head->index == lydt->og_size - 4 || a->head->index == lydt->og_size - 5))
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
		while (a->size > 5 && loop_count++ < start_a_size)
		{
			if (node->index == lydt->og_size - 1 || node->index == lydt->og_size - 2 || node->index == lydt->og_size - 3 || node->index == lydt->og_size - 4 || node->index == lydt->og_size - 5)
				rotate_a(a);
			else if (node->index >= lydt->low && node->index < lydt->top) /*IF IN THE LAYERS, THEN PUSH*/
			{
				node = push_b(a, b);
				if (!node)
					return (-1);
				if (node->next && node->next->index == node->index + 1)
					swap_b(b);
				if (node->index < (size_t)lydt_mid(lydt)) /*ROTATE IF should go under the stack B*/
					rotate_opti_asf(a, b, lydt, &loop_count, start_a_size);
			}
			else
				rotate_a(a);
			node = a->head;
		}
		layer++;
	}
	return (0);
}

/*
Currently, we want to send one layer at a time, in reverse order,
so first last layer, then second to last layer
*/
int	zilla_phaseb(t_llint *a, t_llint *b, t_lydt *lydt)
{
	int		layer;
	t_data	data;

	data.a = a;
	data.b = b;
	data.lydt = lydt;
	layer = lydt->layerzilla;
	while (layer)
	{
		lydt->low = (layer - 1) * (lydt->og_size / lydt->layerzilla);
		lydt->top = (layer) * (lydt->og_size / lydt->layerzilla);
		if (layer == LAYERZILLA)
			lydt->top = lydt->og_size;
		// if (zillasort_layer(a, b, lydt) == -1)
		// 	return (-1);
		if (sortzilla_layersort(&data) == -1)
			return (-1);
		layer--;
	}
	return (0);
}

int	sortzilla(t_llint *a, t_llint *b)
{
	t_lydt		lydt;

	if (!a || !b)
		return (1);
	if (check_sort(a) == -1)
		return (0);
	lydt.og_size = a->size;
	if (a->size <= 5)
		return (sort_five(a, b, &lydt));
	else if (a->size <= 110)
		lydt.layerzilla = LAYERZILLA_SMALL;
	else
		lydt.layerzilla = LAYERZILLA;
	if (zilla_layering(a, b, &lydt))
		return (-1);
	if (sort_five(a, b, &lydt) == -1)
		return (-1);
	if (zilla_phaseb(a, b, &lydt) == -1)
		return (-1);
	return (0);
}
