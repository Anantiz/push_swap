/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zilla_sort_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:32:30 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 13:33:19 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//If on top of stack return 1
static long	search_stack(t_llint *stack, long index)
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
// 1 is top of stack,, negative is stack B
long	where_the_f_is_it(t_llint *a, t_llint *b, long index)
{
	long		position;

	position = search_stack(a, index);
	if (position)
		return (position);
	else
		return (-search_stack(b, index));
}

static long	how_expensive_are_you(t_llint *a, t_llint *b, long index)
{
	long	pos;
	long	cost;

	if (index == -1 || index == (long)a->head->index)
		return (-1);
	pos = search_stack(b, index);
	if (pos < b->size / 2)
		cost = pos;
	else
		cost = -(b->size - pos + 2);
	return (cost);
}

long	who_is_the_cheapest(t_llint *a, t_llint *b, t_lydt *lydt)
{
	long	index;
	long	next_index_cost;
	long	low_index_cost;
	long	cost;

	index = a->head->index - 1;
	next_index_cost = ft_abs_ll(how_expensive_are_you(a, b, index));
	index = lydt->low + lydt->offset;
	low_index_cost = ft_abs_ll(how_expensive_are_you(a, b, index));
	if (next_index_cost < low_index_cost)
		cost = next_index_cost;
	else
		cost = -low_index_cost;
	return (cost);
}

/*
TAKES all layers one by one, as compared to 
zilla_layering who do them 2 by two
*/
void	zilla_move_node(t_llint *a, t_llint *b, long index)
{
	long	position;

	if (!b->head)
	{
		write(2, "Error\n", 6);
		return ;
	}
	position = search_stack(b, index);
	if (position > (b->size / 2))
	{
		while (b->head && (long)b->head->index != index)
			rev_rotate_b(b);
	}
	else
	{
		while (b->head && (long)b->head->index != index)
			rotate_b(b);
	}
	push_a(b, a);
}

long	magic_cheapest(t_llint *a, t_llint *b, t_lydt *lydt)
{
	long	index;
	long	next_index_cost;
	long	low_index_cost;
	long	cost;

	index = a->head->next->index - 1;
	next_index_cost = how_expensive_are_you(a, b, index);
	index = lydt->low + lydt->offset + 1;
	low_index_cost = how_expensive_are_you(a, b, index);
	cost = ft_max_ll(next_index_cost, low_index_cost);
	return (cost);
}

/* NOTE THATE YOU CAN MAYBE PUSH_A EVERYTHING AND ROTATE ONCE YOU HAVE THE RIGHT ONE ON TOP
, but that will make only move_low possilbe*/
int	zillasort_layer(t_llint *a, t_llint *b, t_lydt *lydt)
{
	int		cost;
	
	lydt->offset = 0;
	while (lydt->low + lydt->offset != a->head->index)
	{
		cost = who_is_the_cheapest(a, b, lydt);
		if (cost > 0) /* if bigger than 0 move next, else move first node*/
			zilla_move_node(a, b, a->head->index - 1);
		else
		{
			zilla_move_node(a, b, lydt->low + lydt->offset++);
			if (lydt->low + lydt->offset == a->head->index)
				break ;
			else if (a->head->next && magic_cheapest(a, b, lydt) > 1)
				rotate_rotate(a, b);
			else
				rotate_a(a);
		}
	}
	while (a->last->index < a->head->index)
		rev_rotate_a(a);
	return (0);
}
