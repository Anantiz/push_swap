/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:36 by aurban            #+#    #+#             */
/*   Updated: 2023/11/25 15:39:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	baby_sort(t_llint *stack)
{
	if (!stack)
		return ;
	if (stack->head->data > stack->last->data)
		rotate_a(stack);
	if (stack->head->data > stack->last->data)
		rotate_a(stack);
	else if (stack->head->data > stack->head->next->data)
		swap_a(stack);
	else if (stack->head->next->data > stack->last->data && \
		stack->head->data < stack->head->next->data)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}
