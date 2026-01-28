/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:19:14 by yartym            #+#    #+#             */
/*   Updated: 2026/01/28 11:09:55 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_d_i(t_format *data)
{
	if (data->specifier == 'i' || data->specifier == 'd')
		return (1);
	return (0);
}

int	is_x_X(t_format *data)
{
	if (data->specifier == 'x' || data->specifier == 'X')
		return (1);
	return (0);
}

int	is_flag(char c, t_format *f)
{
	if (c == '-')
		f->dash = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
	else
		return (0);
	return (c);
}

int	is_zero_with_flags(long n, t_format *data)
{
	if (!n && data->precision >= 0)
		return (1);
	return (0);
}

int	is_space_plus_minus(int n, t_format *data)
{
	int i;

	i = 0;
	if (n >= 0 && (data->plus || data->space))
		i = 1;
	else if (n < 0)
		i = 1;
	return (i);
}
