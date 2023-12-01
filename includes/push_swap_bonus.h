/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/12/01 21:15:19 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

/*
OPERATIONS --------------------------------------------------------------------
*/

typedef enum e_operation{
	PUSH_A = 1,
	PUSH_B,
	SWAP_A,
	SWAP_B,
	SWAP_SWAP,
	ROTATE_A,
	ROTATE_B,
	ROTATE_ROTATE,
	REV_ROTATE_A,
	REV_ROTATE_B,
	REV_ROTATE_ROTATE
}t_operation;

t_nodeint	*push_a_log(t_llint *stack_b, t_llint *stack_a, t_llint *log);
t_nodeint	*push_b_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		swap_a_log(t_llint *stack_a, t_llint *log);
void		swap_b_log(t_llint *stack_b, t_llint *log);
void		swap_swap_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		rotate_a_log(t_llint *stack, t_llint *log);
void		rotate_b_log(t_llint *stack, t_llint *log);
void		rr_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		rev_rotate_a_log(t_llint *stack, t_llint *log);
void		rev_rotate_b_log(t_llint *stack, t_llint *log);
void		rev_rr_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

/*
UTILS -------------------------------------------------------------------------
*/

int			push_swap_print_error(int n);
int			util_is_zero(char *str);
int			push_swap_print_error(int n);
int			main_argument_parser(int argc, char **argv, t_llint *stack);
int			clean_b4exit(t_llint *stack_a, t_llint *stack_b);

int			check_sort(t_llint *list);
int			check_duplicates(t_llint *list);

#endif