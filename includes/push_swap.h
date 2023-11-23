/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:13:31 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 12:47:06 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"


/*
---	STACK
*/

/*
t_list	*head
t_list	*s_to_last
t_list	*last
int		len
*/
typedef struct s_stack
{
	t_list	*head;
	t_list	*s_to_last;
	t_list	*t_to_last;
	t_list	*last;
	int		size;
	char	name;
	
}t_stack;

t_stack		*ft_init_stack(char name);
void		stck_free_node_data(void *x)
void		stck_rotate(t_stack *stack)
void		stck_push(t_stack *src, t_stack *dest);

/*
Help_Messages
*/

int			help_no_args(void);

#endif