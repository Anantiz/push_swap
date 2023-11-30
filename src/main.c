/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:07 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 19:37:39 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	util_is_zero(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if ((len == 1 && *str == 0) || (len == 2 && ((*str == '-' || \
		*str == '+') && str[1] == 0)))
		return (1);
	else
		return (0);
}

int	push_swap_print_error(int n)
{
	write(2, "Error\n", 7);
	return (n);
}

static int	main_argument_parser(int argc, char **argv, t_llint *stack)
{
	int		list_size;
	long	node_data;
	int		i;

	list_size = argc - 1;
	i = 1;
	while (i <= list_size)
	{
		node_data = (long)ft_atoll(argv[i]);
		if (node_data == 0 && util_is_zero(argv[i]) == 1)
			return (push_swap_print_error(1));
		if (node_data > INT_MAX || node_data < INT_MIN)
			return (push_swap_print_error(2));
		ft_llint_data_add_back(stack, node_data, 0);
		i++;
	}
	return (check_duplicates(stack));
}
static int	clean_b4exit(t_llint *stack_a, t_llint *stack_b)
{
	ft_llint_del_list(stack_a);
	ft_llint_del_list(stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	int		error;
	t_llint	*stack_a;
	t_llint	*stack_b;

	if (argc == 1)
		return (push_swap_print_error(0));
	stack_a = ft_llint_new();
	stack_b = ft_llint_new();
	error = main_argument_parser(argc, argv, stack_a);
	if (error)
		return (clean_b4exit(stack_a, stack_b));
	give_indexes(stack_a);
	if (stack_a->size > 1 && stack_a->size <= 3)
		baby_sort(stack_a);
	else	
		error = sortzilla(stack_a, stack_b);
	if (error)
		push_swap_print_error(0);
	return (clean_b4exit(stack_a, stack_b));
}
