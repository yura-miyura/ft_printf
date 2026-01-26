/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:42:01 by yartym            #+#    #+#             */
/*   Updated: 2026/01/25 16:38:31 by yartym           ###   ########.fr       */
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
	:



}
//
// int	put_decint
//
// int	put_uint
//
// int	put_pointer
//
// int	put_hex
