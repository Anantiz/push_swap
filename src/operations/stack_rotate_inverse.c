/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_inverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:56 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 19:39:55 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_llint *stack)
{
	ft_llint_rotate_inverse(stack);
	write(1, "rra\n", 4);
}

void	rev_rotate_b(t_llint *stack)
{
	ft_llint_rotate_inverse(stack);
	write(1, "rrb\n", 4);
}

void	rev_rotate_rotate(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_rotate_inverse(stack_a);
	ft_llint_rotate_inverse(stack_b);
	write(1, "rrr\n", 4);
}

/*
LOGS
*/

void	rev_rotate_a_log(t_llint *stack, t_llint *log)
{
	ft_llint_rotate_inverse(stack);
	ft_llint_data_add_back(log, REV_ROTATE_A, 0);
}

void	rev_rotate_b_log(t_llint *stack, t_llint *log)
{
	ft_llint_rotate_inverse(stack);
	ft_llint_data_add_back(log, REV_ROTATE_B, 0);
}
