/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortzilla_layersort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:26:25 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 18:45:45 by aurban           ###   ########.fr       */
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

long move_node_logs(t_data *d, size_t index, t_llint *logs)
{
	long position;
	long cost;

	cost = 0;
	if (!d->b->head)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
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

void get_nimi_cost(t_data *d, size_t nimi, size_t next_i, size_t *cost, t_llint *logs)
{
	int rotated;
	// static int count = 0;

	rotated = 0;
	// printf("Recursive count: %d\t nimi=%lu\t ni= %lu\n",count++, nimi, next_i);
	(*cost) += move_node_logs(d, nimi, logs);
	if (nimi == next_i) /* if nimi(a.k.a i - ammount-to-move) == i, break*/
	{
		// count = 0;
		swap_a_log(d->a, logs);
		(*cost)++;
		return ;
	}
	if (nimi < next_i - 2) /* rotate if not next or next-1*/
	{
		rotate_a_log(d->a, logs);
		rotated = 1;
		(*cost)++;
	}
	// nimi will alway be smaller or equal than next_i, and we want it to go toward n_i
	get_nimi_cost(d, nimi + 1, next_i, cost, logs); /* Call recursively */
	if (rotated)
	{
		rev_rotate_a_log(d->a, logs);
		// (*cost)++;
	}
}
long	search_stack(t_llint *stack, long index)
{
	t_nodeint	*node;
	long		i;

	i = 0;
	node = stack->head;
	while (node)
	{
		i++;
		if ((long)node->index == index)
			return (i);
		node = node->next;
	}	
	return (0);
}
/*
if Under stack, negative value
if Over the stack positive

Always has an absolute value of 1 or higher
*/
long	how_expensive_are_you(t_llint *a, t_llint *b, long index)
{
	long	position;
	long	cost;

	if (index == 0 || index == (long)a->head->index)
		return (-1);
	position = search_stack(b, index);
	if (position < (long)(b->size / 2))
		cost = position;
	else
		cost = (b->size - position) + 1;
	return (cost);
}
/*
if 'index' is 'lowest' -> cost for lowest, if 'i' is 'next', cost for next

AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
if i in between, recursive cost of moving i + ra + i+1 + ra + i+2 +ra ... + rra +rra
*/
long cost_to_move_nimi(t_data *d, size_t nimi)
{
	t_llint	*logs;
	size_t	cost;
	int		mv_count;

	if (nimi == (size_t)lydt_lowest(d->lydt)) // if nimi == lowest
		return (how_expensive_are_you(d->a, d->b, nimi) + 2);
	if (nimi == d->a->head->index - 1) // if nimi ==next
		return (how_expensive_are_you(d->a, d->b, nimi));
	logs = ft_llint_new();
	get_nimi_cost(d, nimi, d->a->head->index - 1, &cost, logs);
	undo_logs(d, logs);
	ft_llint_del_list(logs);
	mv_count = (d->a->head->index - 1 - nimi);
	if (mv_count == 0)
		mv_count = 1;
	// printf("Cost result: %lu / %d\n",cost,mv_count);
	return (cost / (mv_count));
}

static void fill_action_map(t_data *d, size_t *action_map, size_t cheapest_index)
{
	size_t value;
	size_t lowest;

	lowest = lydt_lowest(d->lydt);
	value = 1;
	while (cheapest_index < d->a->head->index)
	{
		action_map[cheapest_index - lowest] = value++;
		cheapest_index++;
	}
}

/*
Action map will be filled such that the first move to do is '1' then the second one is '2' ...
The index start from 'lowest' up until 'next', so next move is the last index
*/
size_t *sortzilla_get_action_map(t_data *d)
{
	size_t	*action_map;
	long	sizeof_layer;
	size_t	cost;
	size_t	cheapest;
	size_t	cheapest_index;
	size_t	nimi;

	sizeof_layer = d->a->head->index - lydt_lowest(d->lydt);
	action_map = ft_calloc(sizeof_layer + 1, sizeof(size_t)); // Action map will be the size of operations to do
	if (!action_map)
		return (NULL);
	cheapest_index = lydt_lowest(d->lydt);
	cheapest = -1;
	nimi = d->a->head->index - 1; // By default nimi == next_index
	while (nimi > (size_t)lydt_lowest(d->lydt))
	{
		// printf("get_map\n");
		//ft_llint_printm(d->a);
		cost = cost_to_move_nimi(d, nimi);
		// printf("nimi= %lu   cost= %lu\n", nimi, cost);
		if (cost < cheapest)
		{
			cheapest = cost;
			// printf("New cheapest-> nimi= %lu\n", nimi);
			cheapest_index = nimi;
		}
		nimi--;
	}
	// ft_llint_printm(d->a);
	// Cheapest index is the real index, and not a relativ index
	// printf("Filling action map: Cheapest index= %lu\n", cheapest_index);
	// printf("low= %lu  top = %lu off= %lu\n", d->lydt->low, d->lydt->top, d->lydt->offset);
	fill_action_map(d, action_map, cheapest_index);
	return (action_map);
}

static int move_lowest_node_under_stack(t_data *d) /* Helper function of "sortzilla_do_action_map"*/
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

int sortzilla_do_action_map(t_data *d, size_t *action_map)
{
	size_t i;
	size_t absolute_index;
	size_t op_count;

	// printf("ENTERING DO ACTION MAP\n\nsize= %lu [",d->a->head->index - lydt_lowest(d->lydt));
	// for (size_t x=0; x <d->a->head->index - lydt_lowest(d->lydt); x++ )
	// 	printf("%lu, ", action_map[x]);
	// printf("]\n");
	// printf("low= %lu  top = %lu off= %lu\n", d->lydt->low, d->lydt->top, d->lydt->offset);
	i = 0;
	while ((action_map[i]) == 0) // Find the first node you should move
		i++;
	op_count = 0;
	while (action_map[i] != 0) // Count how many node to move in total
	{
		op_count++;
		i++;
	}
	if (action_map[0] == 1 && op_count == 1) // Only move last
		return (move_lowest_node_under_stack(d));
	i = 0;
	while ((action_map[i]) == 0) // Find where to start moving
		i++;
	while (action_map[i])
	{
		absolute_index = lydt_lowest(d->lydt) + i;
		// printf("absolute_index: %lu\ti: %lu\n", absolute_index, i);
		if (move_node(d->a, d->b, absolute_index) == -1)
			return (-1);
		if (action_map[i] < op_count - 1) // Rotates node and put them in order at the end
			rotate_a(d->a);
		else if (op_count != 1 && action_map[i] == op_count) // The last ni-i won't be rotate, just swapped with ni
			swap_a(d->a);
		i++;
	}
	while (d->a->last->index != d->lydt->og_size - 1)
	{
		// printf("target: %lu   actual: %lu\n",d->lydt->og_size - 1, d->lydt->top);
		// ft_llint_printm(d->a);
		// exit(0);
		rev_rotate_a(d->a);
	}
	return (0);
}

int sortzilla_layersort(t_data *d)
{
	size_t *action_map;

	d->lydt->offset = 0;
	while (d->a->head->index != (size_t)lydt_lowest(d->lydt)) /* while the head node is not the lowest + offset node of the layer loop*/
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
		fflush(stdout);
	}
	while (d->a->head->index != d->lydt->low) /* Moves every 'low' node that was put under the stack */
	{
		// printf("target: %lu   actual: %lu\n",d->lydt->low, d->a->head->index);
		// ft_llint_printm(d->a);
		// exit(0);
		rev_rotate_a(d->a);
	}
	return (0);
}
