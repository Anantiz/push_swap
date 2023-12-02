/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_inverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:56 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 21:20:30 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
