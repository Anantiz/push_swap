/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:32:47 by aurban            #+#    #+#             */
/*   Updated: 2023/11/25 15:47:25 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_llint *stack)
{
	ft_llint_rotate(stack);
	write(1, "ra\n", 3);
}

void	rotate_b(t_llint *stack)
{
	ft_llint_rotate(stack);
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_rotate(stack_a);
	ft_llint_rotate(stack_b);
	write(1, "rr\n", 2);
}
