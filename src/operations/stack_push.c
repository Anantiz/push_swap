/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:26:51 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 12:34:57 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_llint *stack_b, t_llint *stack_a)
{
	ft_llint_data_add_front(stack_a, stack_b->head->data);
	ft_llint_del_node(stack_b, stack_b->head);
	write(1, "pa\n", 3);
}

void	push_b(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_data_add_front(stack_b, stack_a->head->data);
	ft_llint_del_node(stack_a, stack_a->head);
	write(1, "pb\n", 3);
}
