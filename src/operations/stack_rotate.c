/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:47 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 13:17:53 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_llint *stack)
{
	ft_llint_rotate(stack);
	op_mgcount++;
	write(1, "ra\n", 3);
}

void	rotate_b(t_llint *stack)
{
	ft_llint_rotate(stack);
	op_mgcount++;
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_rotate(stack_a);
	op_mgcount++;
	ft_llint_rotate(stack_b);
	write(1, "rr\n", 3);
}

/*
LOG
*/

void	rotate_a_log(t_llint *stack, t_llint *log)
{
	ft_llint_rotate(stack);
	ft_llint_data_add_back(log, ROTATE_A, 0);
}

void	rotate_b_log(t_llint *stack, t_llint *log)
{
	ft_llint_rotate(stack);
	ft_llint_data_add_back(log, ROTATE_B, 0);
}

void	rotate_rotate_log(t_llint *stack_a, t_llint *stack_b, t_llint *log)
{
	ft_llint_rotate(stack_a);
	ft_llint_data_add_back(log, ROTATE_ROTATE, 0);
	ft_llint_rotate(stack_b);
}

