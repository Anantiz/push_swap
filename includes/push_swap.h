/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 18:19:56 by aurban           ###   ########.fr       */
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

long		lydt_mid(t_lydt *lydt);
long		lydt_lowest(t_lydt *lydt);
long		lydt_layer_size(t_lydt *lydt);
long		lydt_layer_off7size(t_lydt *lydt);

typedef struct s_data
{
	t_llint		*a;
	t_llint		*b;
	t_lydt		*lydt;
}t_data;

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

/* Logged ones*/

void		undo_logs(t_data *d, t_llint *logs);

t_nodeint	*push_a_log(t_llint *stack_b, t_llint *stack_a, t_llint *log);
t_nodeint	*push_b_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		swap_a_log(t_llint *stack_a, t_llint *log);
void		swap_b_log(t_llint *stack_b, t_llint *log);
void		swap_swap_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		rotate_a_log(t_llint *stack, t_llint *log);
void		rotate_b_log(t_llint *stack, t_llint *log);
void		rotate_rotate_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		rev_rotate_a_log(t_llint *stack, t_llint *log);
void		rev_rotate_b_log(t_llint *stack, t_llint *log);
void		rev_rotate_rotate_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

/*
CORE --------------------------------------------------------------------------
*/

extern	size_t op_mgcount;

int			baby_sort(t_llint *stack);
int			sort_five(t_llint *a, t_llint *b, t_lydt *lydt);
int			sortzilla(t_llint *stack_a, t_llint *stack_b);

int			sortzilla_layersort(t_data *d); // Clean
int			zillasort_layer(t_llint *a, t_llint *b, t_lydt *lydt); //Shitty


/*
UTILS -------------------------------------------------------------------------
*/

long		search_stack(t_llint *stack, long index);
int			move_node(t_llint *a, t_llint *b, long index);
long		how_expensive_are_you(t_llint *a, t_llint *b, long index);

int			push_swap_print_error(int n);


/*
FOR LIBFT ---------------------------------------------------------------------
*/

int			check_sort(t_llint *list);
int			check_duplicates(t_llint *list);
long		*ft_llint_to_arr(t_llint *llist);
void		give_indexes(t_llint *list);
void		ft_quicksort(long *list, long low_index, long high_index);

#endif