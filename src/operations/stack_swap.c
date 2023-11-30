/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:24:00 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 13:17:41 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_llint *stack_a)
{
	ft_llint_swap_data_front(stack_a);
	op_mgcount++;
	write(1, "sa\n", 3);
}

void	swap_b(t_llint *stack_b)
{
	ft_llint_swap_data_front(stack_b);
	op_mgcount++;
	write(1, "sb\n", 3);
}

void	swap_swap(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_swap_data_front(stack_a);
	op_mgcount++;
	ft_llint_swap_data_front(stack_b);
	write(1, "ss\n", 3);
}

/*
LOG
*/

void	swap_a_log(t_llint *stack_a, t_llint *log)
{
	ft_llint_swap_data_front(stack_a);
	ft_llint_data_add_back(log, SWAP_A, 0);
}

void	swap_b_log(t_llint *stack_b, t_llint *log)
{
	ft_llint_swap_data_front(stack_b);
	ft_llint_data_add_back(log, SWAP_B, 0);
}

void	swap_swap_log(t_llint *stack_a, t_llint *stack_b, t_llint *log)
{
	ft_llint_swap_data_front(stack_a);
	ft_llint_swap_data_front(stack_b);
	ft_llint_data_add_back(log, SWAP_SWAP, 0);
}
