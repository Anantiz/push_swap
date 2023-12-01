/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:24:00 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 21:20:39 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
