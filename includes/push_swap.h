/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 20:12:13 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define LAYERZILLA_SMALL 8
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

typedef struct s_gl
{
	size_t	next_i;
	size_t	*cost;
}t_gl;

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
void		rr_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

void		rev_rotate_a_log(t_llint *stack, t_llint *log);
void		rev_rotate_b_log(t_llint *stack, t_llint *log);
void		rev_rr_log(t_llint *stack_a, t_llint *stack_b, t_llint *log);

/*
CORE --------------------------------------------------------------------------
*/

int			baby_sort(t_llint *stack);
int			sortzilla(t_llint *stack_a, t_llint *stack_b);
int			sort_five(t_llint *a, t_llint *b, t_lydt *lydt);
int			zilla_phaseb(t_llint *a, t_llint *b, t_lydt *lydt);
long		move_node_logs(t_data *d, size_t index, t_llint *logs);
size_t		*sortzilla_get_action_map(t_data *d);

int			sortzilla_layersort(t_data *d);

/*
UTILS -------------------------------------------------------------------------
*/

int			move_node(t_llint *a, t_llint *b, long index);
long		search_stack(t_llint *stack, long index);
long		how_expensive_are_you(t_llint *a, t_llint *b, long index);

int			push_swap_print_error(int n);
void		get_nimi_cost(t_data *d, size_t nimi, t_gl *gl, t_llint *logs);

/*
FOR LIBFT ---------------------------------------------------------------------
*/

int			check_sort(t_llint *list);
int			check_duplicates(t_llint *list);
long		*ft_llint_to_arr(t_llint *llist);
void		give_indexes(t_llint *list);
void		ft_quicksort(long *list, long low_index, long high_index);

#endif