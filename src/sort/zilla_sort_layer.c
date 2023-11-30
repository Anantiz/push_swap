/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zilla_sort_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:32:30 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 18:34:40 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//If on top of stack return 1
long	shitty_who_is_the_cheapest(t_llint *a, t_llint *b, t_lydt *lydt)
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

int	move_node(t_llint *a, t_llint *b, long index)
{
	long	position;

	if (!b->head)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	position = search_stack(b, index);
	if (position > (long)(b->size / 2))
	{
		while (b->head && (long)b->head->index != index)
			rev_rotate_b(b);
	}
	else
	{
		while (b->head && (long)b->head->index != index)
		{
			rotate_b(b);
		}
	}
	if (push_a(b, a) == NULL)
		return (-1);
	return (0);
}

long	next_round_cheapest(t_llint *a, t_llint *b, t_lydt *lydt)
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
		cost = shitty_who_is_the_cheapest(a, b, lydt);
		if (cost > 0) /* if bigger than 0 move next, else move first node*/
			move_node(a, b, a->head->index - 1);
		else
		{
			move_node(a, b, lydt->low + lydt->offset++);
			if (lydt->low + lydt->offset == a->head->index)
				break ;
			else if (a->head->next && next_round_cheapest(a, b, lydt) > 1)
				rotate_rotate(a, b);
			else
				rotate_a(a);
		}
	}
	while (a->last->index < a->head->index)
		rev_rotate_a(a);
	return (0);
}
