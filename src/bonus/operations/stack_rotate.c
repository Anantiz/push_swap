/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:47 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 21:20:35 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
