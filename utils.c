/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:38 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/25 16:29:41 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	padding(char c, int size)
{
	int	n;

	n = 0;
	while (size)
	{
		ft_putchar_fd(c, 1);
		size--;
		n++;
	}
	return (n);
}

void	dec_to_hex(unsigned long n, int *count, t_format *data)
{
	char *hex;

	hex = "0123456789abcdef";
	if (data->specifier == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		dec_to_hex(n / 16, count, data);
	ft_putchar_fd(hex[n % 16], 1);
	(*count)++;
}

int	hex_prefix(t_format *data)
{
	char	*prefix;

	add = 2;
	prefix = NULL;
	c = data->specifier;
	if ((data->hash && c == 'x') || c == 'p')
		prefix = "0x";
	else if (data->hash && c == 'X')
		prefix = "0X";
	else
		add = 0;
	ft_putstr_fd(prefix, 1);
	return (add);
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
	// else if (c == 'i' || c == 'd')
	// 	n = put_decint(va_arg(*args, int), f);
	// else if (c == 'u')
	// 	n = put_uint(va_arg(*args, unsigned int), f);
	// else if (c == 'p')
	// 	n = put_pointer(va_arg(*args, unsigned long), f);
	// else if (c == 'x' || c == 'X')
	// 	n = put_hex(va_arg(*args, unsigned int), f);
	// else if (c == '%')
	// 	n = put_char('%', f);
	else
		n = put_char(c, data);
	return (n);
}
