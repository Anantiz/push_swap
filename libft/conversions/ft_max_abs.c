/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_abs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurban <aurban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:05:39 by aurban            #+#    #+#             */
/*   Updated: 2023/11/29 10:05:51 by aurban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs_ll(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long long	ft_max_ll(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}
