/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_layersort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:25 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 19:42:52 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_lowest_node_under_stack(t_data *d)
{
	if (move_node(d->a, d->b, lydt_lowest(d->lydt)) == -1)
		return (-1);
	if (d->a->head->next->index != (size_t)(lydt_lowest(d->lydt) + 1))
	{
		rotate_a(d->a);
		d->lydt->offset++;
	}
	return (0);
}

static int	do_action_map2(t_data *d, size_t *act_map, size_t i, size_t count)
{
	size_t	absolute_index;

	while (act_map[i])
	{
		absolute_index = lydt_lowest(d->lydt) + i;
		if (move_node(d->a, d->b, absolute_index) == -1)
			return (-1);
		if (act_map[i] < count - 1)
		{
			if (how_expensive_are_you(d->a, d->b, absolute_index + 1) > 1)
				rotate_rotate(d->a, d->b);
			else
				rotate_a(d->a);
		}
		else if (count != 1 && act_map[i] == count)
			swap_a(d->a);
		i++;
	}
	return (0);
}

int	sortzilla_do_action_map(t_data *d, size_t *action_map)
{
	size_t	i;
	size_t	op_count;

	i = 0;
	while ((action_map[i]) == 0)
		i++;
	op_count = 0;
	while (action_map[i] != 0)
	{
		op_count++;
		i++;
	}
	if (action_map[0] == 1 && op_count == 1)
		return (move_lowest_node_under_stack(d));
	i = 0;
	while ((action_map[i]) == 0)
		i++;
	if (do_action_map2(d, action_map, i, op_count) == -1)
		return (-1);
	while (d->a->last->index != d->lydt->og_size - 1)
		rev_rotate_a(d->a);
	return (0);
}

int	sortzilla_layersort(t_data *d)
{
	size_t	*action_map;

	d->lydt->offset = 0;
	while (d->a->head->index != (size_t)lydt_lowest(d->lydt))
	{
		action_map = sortzilla_get_action_map(d);
		if (!action_map)
			return (-1);
		if (sortzilla_do_action_map(d, action_map))
		{
			free(action_map);
			return (-1);
		}
		free(action_map);
	}
	while (d->a->head->index != d->lydt->low)
		rev_rotate_a(d->a);
	return (0);
}
