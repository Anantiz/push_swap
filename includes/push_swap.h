/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/27 19:41:46 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

# define LAYERZILLA 6

typedef struct s_lydt
{
	size_t	low;
	size_t	top;
	size_t	offset;
}t_lydt;

void		baby_sort(t_llint *stack);
void		sortzilla(t_llint *stack_a, t_llint *stack_b);
void		zillasort_layer(t_llint *a, t_llint *b, t_lydt *lydt);

/*
OPERATIONS
*/

void		push_a(t_llint *stack_b, t_llint *stack_a);
void		push_b(t_llint *stack_a, t_llint *stack_b);

void		swap_a(t_llint *stack_a);
void		swap_b(t_llint *stack_b);
void		swap_swap(t_llint *stack_a, t_llint *stack_b);

void		rotate_a(t_llint *stack);
void		rotate_b(t_llint *stack);
void		rotate_rotate(t_llint *stack_a, t_llint *stack_b);

void		rev_rotate_a(t_llint *stack);
void		rev_rotate_b(t_llint *stack);
void		rev_rotate_rotate(t_llint *stack_a, t_llint *stack_b);

/*
UTILS
*/

int			check_sort(t_llint *list);
int			check_duplicates(t_llint *list);
void		give_indexes(t_llint *list);
int			push_swap_print_error(int n);

long		lydt_mid(t_lydt *lydt);

/*
FOR LIBFT
*/

long		*ft_llint_to_arr(t_llint *llist);
void		ft_quicksort(long *list, long low_index, long high_index);

#endif