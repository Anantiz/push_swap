/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:19 by aurban            #+#    #+#             */
/*   Updated: 2023/11/28 18:24:26 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	zilla_get_layers(t_lydt *lydt, int layer, size_t fs)
{
	layer *= 2;
	lydt->low = layer * (fs / LAYERZILLA);
	layer += 2;
	lydt->top = layer* (fs / LAYERZILLA);
	if (layer == LAYERZILLA)
		lydt->top = fs;
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
int	zilla_layering(t_llint *a, t_llint *b, size_t og_size)
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
		zilla_get_layers(&lydt, layer, og_size);
		while (node && loop_count++ < start_a_size)
		{
			if (node->index >= lydt.low && node->index < lydt.top) /*IF IN THE LAYERS, THEN PUSH*/
			{
				node = push_b(a, b);
				if (!node)
					return (-1) ;
				if (node->index < (size_t)lydt_mid(&lydt)) /*ROTATE IF should go under the stack B*/
					rotate_opti_asf(a, b, lydt.top, &loop_count, start_a_size);
			}
			else
				rotate_a(a);
			node = a->head;
		}
		layer++;
	}
	FILE *fd = fopen("log.txt", "w");
	fprintf(fd, "LAYERING %d: count=%lu\n",layer, op_mgcount);
	fclose(fd);
	return (0);
}

/*
Currently, we want to send one layer at a time, in reverse order,
so first last layer, then second to last layer
*/
void	zilla_phaseb(t_llint *a, t_llint *b, size_t og_size)
{
	t_lydt	lydt;
	int		layer;

	layer = LAYERZILLA;
	zilla_move_node(a ,b , og_size - 1, 0);
	
	while (layer)
	{
		lydt.low = (layer - 1) * (og_size / LAYERZILLA);
		lydt.top = (layer) * (og_size / LAYERZILLA);
		if (layer == LAYERZILLA)
			lydt.top = og_size;
		zillasort_layer(a, b, &lydt);
		FILE *fd = fopen("log.txt", "a");
		fprintf(fd, "Layer % d: low=%lu\ttop=%lu\tcount=%lu\n",layer,lydt.low, lydt.top ,op_mgcount);
		fclose(fd);
		layer--;
	}
}

int	sortzilla(t_llint *a, t_llint *b)
{
	size_t		og_size;

	if (!a || !b)
		return (1);
	if (check_sort(a) == -1)
		return (0);
	give_indexes(a);
	og_size = a->size;
	if (zilla_layering(a, b, og_size)) /* PUSH A TO B within layers (6 groups) */
		return (-1);
	
	t_nodeint *node = b->head;
	size_t i = 0;
	FILE *fd = fopen("stack_a.txt", "w");
	while (node)
	{
		fprintf(fd,"node %ld: %ld\t\tindex= %u\n", i, node->data, (unsigned int)node->index);
		node = node->next;
		i++;
	}
	fclose(fd);
	
	zilla_phaseb(a, b, og_size); /* PUSH BACK INTO A and sorts it*/
	return (0);
}
