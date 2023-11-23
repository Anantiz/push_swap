/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:15:07 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 12:18:03 by aurban           ###   ########.fr       */
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
static int	main_argument_parser(int argc, char **argv, t_stack *stack)
{
	t_list	*new_node;
	int		*node_data;
	int		list_size;
	int		i;

	list_size = argc - 1;
	stack->size = list_size;
	if (list_size <= 0)
		return (help_no_args());
	i = 1;
	while (i <= list_size)
	{
		node_data = malloc(sizeof(int));
		if (!node_data)
			return (error_malloc());
		*node_data = ft_atoi(argv[i]);
		if (node_data == 0 && !util_is_zero(argv[i]))
			return (help_invalid_argument(argv[i]));
		new_node = ft_lstnew(node_data);
		if (!new_node)
			return (error_malloc());
		ft_lstadd_front(&stack->head, new_node);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		error;
	t_stack	*stack_a;
	t_stack	*stack_b;
	
	stack_a = init_stack();
	stack_b = init_stack();
	error = main_argument_parser(argc, argv, stack_a);

	return (0);
}