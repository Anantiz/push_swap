/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_layersort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:25 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 11:17:46 by aurban           ###   ########.fr       */
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


/*
Action map will be filled such that the first move to do is '1' then the second one is '2' ...
The index start from lowest up until next, so next move is the last index
*/
size_t	*sortzilla_get_action_map(t_data *d)
{
	size_t	*action_map;
	long	sizeof_layer;
	
	sizeof_layer = lydt_layer_off7size(d->lydt);
	action_map = ft_calloc(sizeof_layer + 1, sizeof(size_t));
	if (!action_map)
		return (NULL);
	// Now fill the map, based on what do you want to do
	/*
	TO DO
	*/
}

static int	move_lowest_node_under_stack(t_data *d)
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
