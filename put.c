/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:42:01 by yartym            #+#    #+#             */
/*   Updated: 2026/01/28 11:24:35 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c, t_format *data)
{
	int	n;
	int	width;

	n = 1;
	width = data->width - n;
	if (!data->dash && width > 0)
		n += padding(' ', width);
	ft_putchar_fd(c, 1);
	if (data->dash && width > 0)
		n += padding(' ', width);
	return (n);
}

int	put_str(char *str, t_format *data)
{
	int	count;
	int	len;
	int	width;

	count = 0;
	if (!str)
	{
		if (data->precision < 0 || data->precision > 5)
			str = "(null)";
		else
			str = "";
	}
	len = ft_strlen(str);
	if (data->precision >= 0 && len > data->precision)
		len = data->precision;
	width = data->width - len;
	if (!data->dash && width > 0)
		count += padding(' ', width);
	count += len;
	while (len--)
		ft_putchar_fd(*str++, 1);
	if (data->dash && width > 0)
		count += padding(' ', width);
	return (count);
}

int	put_pointer(unsigned long n, t_format *data)
{
	int		count;
	int		width;
	int		len;

	count = 0;
	len = 5;
	if (n)
		len = hex_len(n) + 2;
	count += len;
	width = data->width - len;
	if (!data->dash && width > 0)
		count += padding(' ', width);
	if (n)
	{
		hex_prefix(data);
		pnt_hex(n, data->specifier);
	}
	else
		ft_putstr_fd("(nil)", 1);
	if (data->dash && width > 0)
		count += padding(' ', width);
	return (count);
}

int	put_number(long n, t_format *data)
{
	int		count;
	int		width;
	int		len;

	len = len_number(n, data);
	count = len;
	width = data->width - len;
	if (is_x(data) && n && data->hash)
	{
		width -= 2;
		count += 2;
	}
	if (data->precision > len)
		width -= data->precision - len;
	if (is_d_i(data) && is_space_plus_minus(n, data))
		width--;
	count += width_padding(width, data);
	if (is_d_i(data))
		count += space_plus_minus(n, data);
	else if (n && is_x(data))
		hex_prefix(data);
	count += zero_padding(len, width, data);
	pnt_type_number(n, data);
	count += dash_padding(width, data);
	return (count);
}
