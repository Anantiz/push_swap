/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baby_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:00:36 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 13:26:54 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	baby_sort(t_llint *stack)
{
	if (!stack)
		return ;
	ft_printf("AA\n");
	fflush(NULL);
	if (stack->head > stack->last)
	{
		ft_printf("B\n");
		fflush(NULL);
		rotate_a(stack);
	}
	if (stack->head > stack->last)
		rotate_a(stack);
	else if (stack->head > stack->head->next)
		swap_a(stack);
	else if (stack->head->next > stack->last && stack->head < stack->head->next)
	{
		swap_a(stack);
		rotate_a(stack);
	}
}
