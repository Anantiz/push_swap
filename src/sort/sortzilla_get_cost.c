/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_get_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:21:42 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 20:16:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_nimi_cost(t_data *d, size_t nimi, t_gl *gl, t_llint *logs)
{
	(*gl->cost) += move_node_logs(d, nimi, logs);
	if (nimi == gl->next_i)
	{
		swap_a_log(d->a, logs);
		(*gl->cost)++;
		return ;
	}
	else if (nimi < gl->next_i - 2)
	{
		rotate_a_log(d->a, logs);
		(*gl->cost)++;
	}
	get_nimi_cost(d, nimi + 1, gl, logs);
}

long	move_node_logs(t_data *d, size_t index, t_llint *logs)
{
	long	position;
	long	cost;

	cost = 0;
	position = search_stack(d->b, index);
	if (position > (long)(d->b->size / 2))
	{
		while (d->b->head && d->b->head->index != index)
		{
			rev_rotate_b_log(d->b, logs);
			cost++;
		}
	}
	else
	{
		while (d->b->head && d->b->head->index != index)
		{
			rotate_b_log(d->b, logs);
			cost++;
		}
	}
	if (push_a_log(d->b, d->a, logs) == NULL)
		return (-1);
	cost++;
	return (cost);
}

static long	cost_to_move_nimi(t_data *d, size_t nimi)
{
	t_llint	*logs;
	size_t	cost;
	int		mv_count;
	t_gl	gl;

	if (nimi == (size_t)lydt_lowest(d->lydt))
		return (ft_abs_ll(how_expensive_are_you(d->a, d->b, nimi)) + 2);
	if (nimi == d->a->head->index - 1)
		return (ft_abs_ll(how_expensive_are_you(d->a, d->b, nimi)));
	logs = ft_llint_new();
	gl.next_i = d->a->head->index - 1;
	gl.cost = &cost;
	get_nimi_cost(d, nimi, &gl, logs);
	undo_logs(d, logs);
	ft_llint_del_list(logs);
	mv_count = (d->a->head->index - 1 - nimi);
	if (mv_count == 0)
		mv_count = 1;
	return (cost / (mv_count) / 4);
}

static void	fill_action_map(t_data *d, size_t *action_map, size_t cheapest_i)
{
	size_t	value;
	size_t	lowest;

	lowest = lydt_lowest(d->lydt);
	value = 1;
	while (cheapest_i < d->a->head->index)
	{
		action_map[cheapest_i - lowest] = value++;
		cheapest_i++;
	}
}

size_t	*sortzilla_get_action_map(t_data *d)
{
	size_t	*action_map;
	size_t	cost;
	size_t	cheapest;
	size_t	cheapest_index;
	size_t	nimi;

	action_map = ft_calloc(d->a->head->index - lydt_lowest(d->lydt) \
	+ 1, sizeof(size_t));
	if (!action_map)
		return (NULL);
	cheapest_index = lydt_lowest(d->lydt);
	cheapest = -1;
	nimi = d->a->head->index - 1;
	while (nimi > (size_t)lydt_lowest(d->lydt))
	{
		cost = cost_to_move_nimi(d, nimi);
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_index = nimi;
		}
		nimi--;
	}
	fill_action_map(d, action_map, cheapest_index);
	return (action_map);
}
