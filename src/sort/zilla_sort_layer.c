/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zilla_sort_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:32:30 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 19:38:13 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	zillasort_upper(t_llint *stack_a, t_llint *stack_b, size_t og_size)
{
	int	cost;
	
	what_index_do_i_want();// I want 1 above or under top ; I want one under bottom
	where_is_index(); // Find the Indexes; return it's position from the top in A or B, negative if it's from B
	evaluate_options(); // How expensives are each to get into place, and will it fck me up ?
	// BRANCH If it fucked me up, return
		take_cheapest();
		cost = zilla_sort_upper(); // Move the Index that you chose to mobe
		if_shitty_go_back_branch(); // IF it turns out shitty later or, go back, move an other one, or differently
}*/

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
static long	where_the_f_is_it(t_llint *a, t_llint *b, long index)
{
	long		position;

	position = search_stack(a, index);
	if (position)
		return (position);
	else
		return (-search_stack(b, index));
}

static void	how_expensive_are_you(t_llint *a, t_llint *b, t_lydt *lydt, long *cost, long i, long next_count, int loop_count)
{
	long	pos;

	if (i == -1 || i == (long)a->head->index || loop_count >= 4)
		return ;
	pos = search_stack(b, i);
	if (pos < (long)lydt->top)
	{
		*cost += pos;
		next_count++;
	}
	else
	{
		*cost += b->size - pos + 3;
		lydt->offset++;
	}
	loop_count++;
	how_expensive_are_you(a, b, lydt, cost, a->head->index - next_count - 1, next_count, loop_count);
	how_expensive_are_you(a, b, lydt, cost, lydt->low + lydt->offset, next_count, loop_count);
}

int	who_is_the_cheapest(t_llint *a, t_llint *b, t_lydt *lydt)
{
	long	index;
	long	next_index_cost;
	long	low_index_cost;
	long	cost;

	index = a->head->index - 1;
	next_index_cost = 0;
	how_expensive_are_you(a, b, lydt, &next_index_cost, index, 0, 0);
	
	index = lydt->low + lydt->offset;
	low_index_cost = 0;
	how_expensive_are_you(a, b, lydt, &low_index_cost, index, 0, 0);
	 
	if (next_index_cost < low_index_cost)
		cost = next_index_cost;
	else
		cost = -low_index_cost;
	printf("Cost:%ld\n",cost);
	return (cost >= 0);
}
void	zilla_move_next(t_llint *a, t_llint *b)
{
	long	index;

	index = a->head->index - 1;
	where_the_f_is_it(a, b, index);
	if (index > (b->size / 2))
	{
		while ((long)b->head->index != index && b->head)
			rev_rotate_b(b);
	}
	else
	{
		while ((long)b->head->index != index && b->head)
			rotate_b(b);
	}
	push_a(b, a);
}

void	zilla_move_low(t_llint *a, t_llint *b, t_lydt *lydt)
{
	long	index;

	if (!a->head || !b->head)
	{
		write(2, "WTF\n", 4);
		return ;
	}
	index = lydt->low + lydt->offset - 1;
	where_the_f_is_it(a, b, index);
	if (index > (b->size / 2))
	{
		while ((long)b->head->index != index)
			rev_rotate_b(b);
	}
	else
	{
		while ((long)b->head->index != index)
			rotate_b(b);
	}
	push_a(b, a);
}

/* NOTE THATE YOU CAN MAYBE PUSH_A EVERYTHING AND ROTATE ONCE YOU HAVE THE RIGHT ONE ON TOP
, but that will make only move_low possilbe*/
void	zillasort_layer(t_llint *a, t_llint *b, t_lydt *lydt)
{
	size_t	copy_offset;
	
	lydt->offset = 0;
	while (lydt->low + lydt->offset != a->head->index)
	{
		copy_offset = lydt->offset;
		if (who_is_the_cheapest(a, b, lydt))
		{
			zilla_move_next(a, b);
		}
		else
		{
			lydt->offset = copy_offset + 1;
			zilla_move_low(a, b, lydt);
		}
	}
	while (a->last->index < a->head->index)
		rev_rotate_a(a);
}
