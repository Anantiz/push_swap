/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:36 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 19:02:38 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	baby_sort(t_llint *stack)
{
	if (!stack || !stack->head)
		return ;
	if (stack->head->index > stack->last->index)
		rotate_a(stack);
	if (stack->head->index > stack->last->index)
		rotate_a(stack);
	else if (stack->head->next && stack->head->index > stack->head->next->index)
		swap_a(stack);
	else if (stack->head->next && stack->head->next->index > \
		stack->last->index && stack->head->index < stack->head->next->index)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}

void	sort_five(t_llint *a, t_llint *b, t_lydt *lydt)
{
	long	og_size_b;
	
	og_size_b = b->size;
	if (a->last->index == (lydt->og_size - a->size))
		rev_rotate_a(a);
	while (a->last->index != lydt->og_size - 1)
	{
		if (a->head->index == (lydt->og_size - a->size))
			push_b(a, b);
		else
			rotate_a(a);
	}
	while (a->size > 3)
	{
		push_b(a , b);
		if (b->head->next && b->head->next->index > b->head->index)
			swap_b(b);
	}
	baby_sort(a);
	while (a->size != 5 || check_sort(a) != -1)
	{
		if (b->head && a->head->index < b->head->index)
			rotate_a(a);
		else if (a->last->index == a->head->index - 1)
			rev_rotate_a(a);	
		else if (b->head->index == a->head->index - 1)
			push_a(b, a);
		else if (b->size == og_size_b && a->last->index != (lydt->og_size - a->size))
			rev_rotate_a(a);
	}
}