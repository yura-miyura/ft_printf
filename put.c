/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:42:01 by yartym            #+#    #+#             */
/*   Updated: 2026/01/27 14:34:28 by yartym           ###   ########.fr       */
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
	int	n;
	int	len;
	int	width;

	n = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (data->precision >= 0 && len > data->precision)
		len = data->precision;
	width = data->width - len;
	if (!data->dash && width > 0)
		n += padding(' ', width);
	while (len--)
	{
		ft_putchar_fd(*str++, 1);
		n++;
	}
	if (data->dash && width > 0)
		n += padding(' ', width);
	return (n);
}

int	put_pointer(unsigned long n, t_format *data)
{
	int		count;
	int		width;
	int		len;

	count = 0;
	if (n)
	{
		len = hex_len(n);
		len += hex_prefix(data);
	}
	else
		len = 5;
	count += len;
	width = data->width - len;
	if (!data->dash && width > 0)
		count += padding(' ', width);
	if (n)
		dec_to_hex(n, data->specifier);
	else
		ft_putstr_fd("(nil)", 1);
	if (data->dash && width > 0)
		count += padding(' ', width);
	return (count);
}


int	put_decint(int n, t_format *data)
{
	int		count;
	int		width;
	int		len;

	count = 0;
	len = ft_strlen(ft_itoa(n));
	if (n < 0)
		len--;
	count += len;
	width = data->width - len;
	if (data->precision >= 0)
		width -= data->precision - len;
	if (n >= 0 && (data->plus || data->space))
		width -= 1;
	count += width_padding(width, data);
	count += space_plus_minus(n, data);
	count += zero_padding(len, width, data);
	put_num_pos(n);
	count += dash_padding(width, data);
	return (count);
}

// int	put_uint
//
// int	put_hex
