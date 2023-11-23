/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_object_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:32:50 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 12:47:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_init_stack(char name)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->head = ft_lst_new(NULL);
	new_stack->t_to_last = NULL;
	new_stack->s_to_last = NULL;
	new_stack->last = new_stack->head;
	new_stack->name = name;
}

void	stck_free_node_data(void *x)
{
	free(x)
}
