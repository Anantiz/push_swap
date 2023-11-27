/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 14:23:37 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(size_t *low , size_t *high, int layer, int fs)
{
	*low = layer * 2 * (fs / LAYERZILLA);
	*high = (layer + 1) * 2 * (fs / LAYERZILLA);
}

/*
PUSH TO B WITH LAYERING
*/
void	sortzilla_layering(t_llint *stack_a, t_llint *stack_b, size_t og_size)
{
	t_nodeint	*node;
	size_t		low_layer;
	size_t		top_layer;
	int			layer;
	
	layer = 0;
	while (layer < (LAYERZILLA / 2))
	{
		zilla_get_layers(&low_layer, &top_layer, layer, og_size);
		node = stack_a->head;
		while (node)
		{
			if (node->index >= low_layer && node->index < top_layer) /*IF IN THE LAYERS, THEN PUSH*/
			{
				push_b(stack_a, stack_b);
				if (node->index > (top_layer - low_layer) / 2) /*ROTATE IF ON SMALL SIDE*/
					if (node->next && node->next->index > top_layer) /* OPTIMIZE SHIT*/
						rotate_rotate(stack_a, stack_b);
					else
						rotate_a(stack_a);
			}
			else
				rotate_a(stack_a);
		}
	}
}

void	sortzilla_sort(t_llint *stack_a, t_llint *stack_b, size_t og_size)
{
	
}

void	sortzilla(t_llint *stack_a, t_llint *stack_b)
{
	size_t		og_size;

	if (!stack_a || !stack_b)
		return ;
	give_indexes(stack_a);
	og_size = stack_a->size;
	sortzilla_layering(stack_a, stack_b, og_size);
	shove_back_b_in_a(stack_a, stack_b, og_size);
}
