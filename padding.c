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

// void	put_nil(t_format *data)
// {
// 	ft_putstr_fd("(nil)", 1);
// 	data->length = 5;
// }

// void put_u_int(unsigned int n, int *count)
// {
// 	if (n >= 10)
// 		ft_put_uint(n / 10, count);
// 	ft_putchar_fd((n % 10 + '0'), 1);
// 	(*count)++;
// }
//
// int put_str(char *str)
// {
// 	int len;
//
// 	if (str == NULL)
// 		str = "(null)";
// 	ft_putstr_fd(str, 1);
// 	len = ft_strlen(str);
// 	return (len);
// }
//
// int	put_dec_int(int n)
// {
// 	char *str;
// 	int len;
//
// 	str = ft_itoa(n);
// 	ft_putstr_fd(str, 1);
// 	len = ft_strlen(str);
// 	free(str);
// 	return (len);
// }
//
// void	ft_put_pointer(unsigned long number, int *count)
// {
// 	if (number > 0)
// 	{
// 		ft_putstr_fd("0x", 1);
// 		*count += 2;
// 		dec_to_hex(number, 'x', count);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("(nil)", 1);
// 		*count += 5;
// 	}
// }

int	convert(va_list *args, t_format *data)
{
	int		n;
	char	c;

	n = 0;
	c = data->specifier;
	if (c == 'c')
		n = put_char(va_arg(*args, int), data);
	else if (c == 's')
		n = put_str(va_arg(*args, char *), data);
	else if (c == 'i' || c == 'd')
		n = put_decint(va_arg(*args, int), data);
	// else if (c == 'u')
	// 	n = put_uint(va_arg(*args, unsigned int), f);
	else if (c == 'p')
		n = put_pointer(va_arg(*args, unsigned long), data);
	// else if (c == 'x' || c == 'X')
	// 	n = put_hex(va_arg(*args, unsigned int), f);
	// else if (c == '%')
	// 	n = put_char('%', f);
	else
		n = put_char(c, data);
	return (n);
}
