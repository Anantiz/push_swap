/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:07 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 13:16:24 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	util_is_zero(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = ft_strlen(str);
	if ((len == 1 && *str == 0) || (len == 2 && ((*str == '-' ||\
		 *str == '+') && str[1] == 0)))
		return (1);
	else
		return (0);
}

/*
returns:
	 0 : OK
	-1 : clean_everything
*/
static int	main_argument_parser(int argc, char **argv, t_llint *stack)
{
	int		list_size;
	int		node_data;
	int		i;

	list_size = argc - 1;
	if (list_size <= 0)
		return (help_no_args());
	i = 1;
	while (i <= list_size)
	{
		node_data = ft_atoi(argv[i]);
		if (node_data == 0 && util_is_zero(argv[i]) == 1)
			return (help_invalid_argument(argv[i]));
		ft_llint_data_add_back(stack, node_data);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		error;
	t_llint	*stack_a;
	//t_llint	*stack_b;
	
	stack_a = ft_llint_new();
	//stack_b = ft_llint_new();
	error = main_argument_parser(argc, argv, stack_a);
	if (error == 1)
	{
		ft_llint_del_list(stack_a);
		return (0);
	}
	if (stack_a->size <= 3)
		baby_sort(stack_a);
	return (0);
}