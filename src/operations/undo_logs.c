/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo_logs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:14:18 by aurban            #+#    #+#             */
/*   Updated: 2023/11/30 13:27:38 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	undo_logs_2(t_data *d, t_llint *logs)
{
	if (logs->last->data == ROTATE_A)
		rev_rotate_a_log(d->a, NULL);
	else if (logs->last->data == ROTATE_B)
		rev_rotate_b_log(d->b, NULL);
	else if (logs->last->data == ROTATE_ROTATE)
		rev_rotate_rotate_log(d->a, d->b, NULL);
	else if (logs->last->data == REV_ROTATE_A)
		rotate_a_log(d->a, NULL);
	else if (logs->last->data == REV_ROTATE_B)
		rotate_b_log(d->b, NULL);
	else if (logs->last->data == REV_ROTATE_ROTATE)
		rotate_rotate_log(d->a, d->b, NULL);
}

void	undo_logs(t_data *d, t_llint *logs)
{
	t_nodeint	*node;

	if (!logs || !logs->last)
		return ;
	node = logs->last;
	while (node)
	{
		if (logs->last->data == PUSH_A)
			push_b_log(d->a, d->a, NULL);
		else if (logs->last->data == PUSH_B)
			push_a_log(d->b, d->a, NULL);
		else if (logs->last->data == SWAP_A)
			swap_a_log(d->a, NULL);
		else if (logs->last->data == SWAP_B)
			swap_b_log(d->b, NULL);
		else
			undo_logs_2(d, logs);
		node = node->previous;
	}
}
