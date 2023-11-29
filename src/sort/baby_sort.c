/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:36 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 11:12:57 by aurban           ###   ########.fr       */
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
