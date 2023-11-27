/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_inverse.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:41:56 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 19:10:49 by aurban           ###   ########.fr       */
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
