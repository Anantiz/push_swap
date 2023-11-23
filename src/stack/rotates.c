/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:36:26 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 12:49:51 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stck_rotate(t_stack *stack)
{

	stack->last->next = stack->head;
	stack->head = stack->head->next;
	stack->s_to_last = stack->s_to_last->next;
	stack->last->next = NULL;
	if (stack->name == 'A')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	stck_rotate_inv(t_stack *stack)
{

	stck_add_front(stack->last);

	head->next = NULL;
	if (stack->name == 'A')
		write(1, "rra\n", 3);
	else
		write(1, "rrb\n", 3);
}
