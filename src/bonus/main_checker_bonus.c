/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:00:24 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 21:24:11 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

	push_swap_checker()

int	main(int argc, char **argv)
{
	int		error;
	t_llint	*stack_a;
	t_llint	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = ft_llint_new();
	stack_b = ft_llint_new();
	if (!stack_a || !stack_b)
		return (1);
	error = main_argument_parser(argc, argv, stack_a);
	if (error)
		return (clean_b4exit(stack_a, stack_b));
	error = push_swap_checker(stack_a, stack_b);
	if (error)
		push_swap_print_error(0);
	return (clean_b4exit(stack_a, stack_b));
}
