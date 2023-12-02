/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:00:24 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 22:20:52 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	checker_operations(t_llint *a, t_llint *b, char *str)
{
	if (!ft_strncmp(str, "ra\n", 4))
		rotate_a_log(a, NULL);
	else if (!ft_strncmp(str, "rb\n", 4))
		rotate_b_log(b, NULL);
	else if (!ft_strncmp(str, "sa\n", 4))
		swap_a_log(a, NULL);
	else if (!ft_strncmp(str, "sb\n", 4))
		swap_b_log(b, NULL);
	else if (!ft_strncmp(str, "ss\n", 4))
		swap_swap_log(a, b, NULL);
	else if (!ft_strncmp(str, "pa\n", 4))
		push_a_log(b, a, NULL);
	else if (!ft_strncmp(str, "pb\n", 4))
		push_b_log(a, b, NULL);
	else if (!ft_strncmp(str, "rr\n", 4))
		rr_log(a, b, NULL);
	else if (!ft_strncmp(str, "rrr\n", 5))
		rev_rr_log(a, b, NULL);
	else if (!ft_strncmp(str, "rra\n", 5))
		rev_rotate_a_log(a, NULL);
	else if (!ft_strncmp(str, "rrb\n", 5))
		rev_rotate_a_log(b, NULL);
	else
		return (1);
	return (0);
}

int	push_swap_checker(t_llint *a, t_llint *b)
{
	size_t	nread;
	char	*line;

	nread = 1;
	while (nread)
	{
		line = get_next_line(0, 0);
		nread = ft_strlen(line);
		if (nread)
		{
			if (checker_operations(a, b, line))
			{
				free(line);
				return (1);
			}
		}
		free(line);
	}
	return (0);
}

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
	else
	{
		if (check_sort(stack_a) == -1 && stack_b->head == NULL)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	return (clean_b4exit(stack_a, stack_b));
}
