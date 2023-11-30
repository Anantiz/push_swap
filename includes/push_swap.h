/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 11:11:23 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
#include <stdio.h>

# define LAYERZILLA_SMALL 6
# define LAYERZILLA 16

/*
low
top
offset
layerzilla
og_size
*/
typedef struct s_lydt
{
	size_t	low;
	size_t	top;
	size_t	offset;
	size_t	layerzilla;
	size_t	og_size;
}t_lydt;

typedef struct s_data
{
	t_llint		*a;
	t_llint		*b;
	t_lydt		*lydt;
}t_data;


extern	size_t op_mgcount;

int			baby_sort(t_llint *stack);
int			sort_five(t_llint *a, t_llint *b, t_lydt *lydt);
int			sortzilla(t_llint *stack_a, t_llint *stack_b);
int			zillasort_layer(t_llint *a, t_llint *b, t_lydt *lydt);

long		search_stack(t_llint *stack, long index);
long		where_the_f_is_it(t_llint *a, t_llint *b, long index);
int			zilla_move_node(t_llint *a, t_llint *b, long index);

long		lydt_lowest(t_lydt *lydt);

/*
OPERATIONS
*/

t_nodeint	*push_a(t_llint *stack_b, t_llint *stack_a);
t_nodeint	*push_b(t_llint *stack_a, t_llint *stack_b);

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
long		lydt_layer_size(t_lydt *lydt);
long		lydt_layer_off7size(t_lydt *lydt);

/*
FOR LIBFT
*/

long		*ft_llint_to_arr(t_llint *llist);
void		ft_quicksort(long *list, long low_index, long high_index);

#endif