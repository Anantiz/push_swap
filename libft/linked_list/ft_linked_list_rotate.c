/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linked_list_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:31:21 by aurban            #+#    #+#             */
/*   Updated: 2023/11/23 17:03:27 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_llint_rotate(t_llint *list)
{
	list->last->next = list->head;
	list->head->previous = list->last;
	list->last = list->last->next;
	list->head = list->head->next;
	list->last->next = NULL;
	list->head->previous = NULL;
}
