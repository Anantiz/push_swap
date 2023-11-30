/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_layersort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:25 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 12:30:45 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Instead of searching either next or lowest check these:
	next,
	lowest,
	for 
		next.index - 1 + next + swap
		next.index - 2 + rotate + next - 1 + next + swap + rev_rotate
		....
	


*/

void	get_i_cost(d, nimi, i, size_t *cost, t_llint *logs)
{
	cost = move_node_log(d, i - nimi, logs);
	
}

/*
if 'i' is lowest, cost for lowest, if i = next, cost for nest

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
if i in between, recursive cost of moving i + ra + i+1 + ra + i+2 +ra ... + rra +rra
*/
long	cost_to_move_i(t_data *d, size_t index)
{
	size_t	ni; //absolute index of next index to put on a
	size_t	nimi; // relative index from ni to x where x is the node-index to put under a
	t_llint	*logs;
	size_t	cost;
	
	ni = d->a->head->index;
	if (i == lydt_lowest(d->lydt))
		return (how_expensive_are_you(d->a, d->b, index) + 2);
	if (i == d->a->head->index - 1))
		return (how_expensive_are_you(d->a, d->b, index));
	logs = ft_llint_new();
	/*
	'index' is relative to lowest, nimi be relative to ni
	*/
	nimi = ni - lydt_lowest(d->lydt);
	get_i_cost(nimi, ni, &cost, logs);
	undo_logs();
	ft_llint_del_list(logs);
	return (cost);
}

/*
Action map will be filled such that the first move to do is '1' then the second one is '2' ...
The index start from lowest up until next, so next move is the last index
*/
size_t	*sortzilla_get_action_map(t_data *d)
{
	size_t	*action_map;
	long	sizeof_layer;
	size_t	cost;
	size_t	cheapest;
	size_t	cheapest_index;
	
	sizeof_layer = lydt_layer_off7size(d->lydt);
	action_map = ft_calloc(sizeof_layer + 1, sizeof(size_t));
	if (!action_map)
		return (NULL);
	// Now fill the map, based on what do you want to do
	/*
	TO DO
	
	Estimate the cheapest operations amongst , lowest, next, next - i
	if next - i is chosen
		recursively calculate what will be the cheaper, you can perform stack operations and log them
		after each recursion, undo the operation that where done
	Finally , fill the action map with the actions to do
	*/
	cheapest = -1;
	i = lydt
	while (i > lydt_lowest(d->lydt))
	{
		cost = cost_to_move_i(d, i);
		if (cost < cheapest)
		{
			cheapest = cost;
			cheapest_index = i;
		}
		i--;
	}
	return (action_map);
}

static int	move_lowest_node_under_stack(t_data *d) /* Helper function of "sortzilla_do_action_map"*/
{
	size_t	position;
	
	position = search_stack(lydt_lowest(d->lydt) + i);
	if (move_node(d->a, d->b , position) == -1)
		return (-1);
	rotate_a(d->a);
	d->lydt->offset++;
	return (0);
}

int	sortzilla_do_action_map(t_data *d, size_t *action_map)
{
	size_t	i;
	size_t	position;
	size_t	op_count;

	i = 0;
	while ((action_map[i]) == 0) // Find the last node you should move
		i++;
	op_count = action_map[i];
	if (i == 1 && op_count == 1)
		return (move_lowest_node_under_stack(d));
	while ((action_map[i]) != 1) // Find the first node you should move
		i++;
	while (action_map[i])
	{
		position = search_stack(lydt_lowest(d->lydt) + i); /* 'i' is the 'layer-index so: bottom_of_the_layer_index + layer-index = actual_index*/
		if (move_node(d->a, d->b , position) == -1)
			return (-1);
		if (action_map[i] < op_count - 2)
			rotate_a(d->a);
		i--;
	}
	while(d->a->last->index != d->lydt->og_size - 1 && d->a->last->index != lydt_lowest(lydt))
		rev_rotate(d->a);
	return (0);
}

int	sortzilla_layersort(t_data *d)
{
	size_t	*action_map;

	d->lydt->offset = 0;
	while (d->a->head->index != lydt_lowest(d->lydt)) /* while the head node is not the lowest + offset node of the layer loop*/
	{
		action_map = sortzilla_get_action_map(data);
		if (!action_map)
			return (-1);
		sortzilla_do_action_map(data, action_map);
		free(action_map);
	}
	while(d->a->head->index != d->lydt->low) /* Moves every 'low' node that was put under the stack */
		rev_rotate(d->a);
	return (0);
}
