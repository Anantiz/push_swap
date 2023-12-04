/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   various_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:17:19 by aurban            #+#    #+#             */
/*   Updated: 2023/12/04 21:08:04 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_not_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !(str[i] == '+' || str[i] == '-'))
			return (1);
		i++;
	}
	return (0);
}

int	push_swap_print_error(int n)
{
	write(2, "Error\n", 7);
	return (n);
}

int	main_argument_parser(int argc, char **argv, t_llint *stack)
{
	int		list_size;
	long	node_data;
	int		i;

	list_size = argc - 1;
	i = 1;
	while (i <= list_size)
	{
		if (is_not_number(argv[i]))
			return (push_swap_print_error(1));
		node_data = (long)ft_atoll(argv[i]);
		if (node_data > INT_MAX || node_data < INT_MIN)
			return (push_swap_print_error(2));
		ft_llint_data_add_back(stack, node_data, 0);
		i++;
	}
	return (check_duplicates(stack));
}

int	clean_b4exit(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_del_list(stack_a);
	ft_llint_del_list(stack_b);
	return (0);
}
