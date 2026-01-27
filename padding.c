/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:38 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/27 13:58:58 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	zero_padding(int len, int width, t_format *data)
{
	int n;

	n = 0;
	if (data->precision < 0 && !data->dash && width > 0)
		n += padding('0', width);
	else if (data->precision > len)
		n += padding('0', data->precision - len);
	return (n);
}

int	width_padding(int width, t_format *data)
{
	int n;

	n = 0;
	if (!data->dash && width > 0 && (!data->zero || data->precision > 0))
		n += padding(' ', width);
	return (n);
}

int	dash_padding(int width, t_format *data)
{
	int	n;

	n = 0;
	if (data->dash && width > 0)
		n += padding(' ', width);
	return (n);
}

int	padding(char c, int size)
{

	int	n;

	n = 0;
	while (size > 0)
	{
		ft_putchar_fd(c, 1);
		size--;
		n++;
	}
	return (n);
}

