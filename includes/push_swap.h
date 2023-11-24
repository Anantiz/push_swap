/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/24 16:46:11 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void		baby_sort(t_llint *stack);
void		sortzilla(t_llint *stack_a, t_llint *stack_b);

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

void		rotate_inv_a(t_llint *stack);
void		rotate_inv_b(t_llint *stack);
void		inv_rotate_rotate(t_llint *stack_a, t_llint *stack_b);

/*
UTILS
*/

int			check_sort(t_llint *list);
int			check_duplicates(t_llint *list);

#endif