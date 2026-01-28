/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:32:32 by yartym            #+#    #+#             */
/*   Updated: 2026/01/28 09:43:55 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	u_int_len(unsigned int n)
{
	int count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	int_len(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (11);
		n *= -1;
	}
	else if (n == 0)
		count++;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	hex_len(unsigned long n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int len_number(long n, t_format *data)
{
	int	len;

	len = 0;
	if (is_d_i(data))
		len = int_len(n);
	else if (is_x_X(data))
		len = hex_len(n);
	else
		len = u_int_len(n);
	return (len);
}

