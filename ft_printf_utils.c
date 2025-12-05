/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:26:42 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/12/01 13:55:11by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dec_to_hex(unsigned long n, char c)
{
	char *hex;

	if (c == 'l' || c == 'p')
		hex = "0123456789abcdef";
	else if (c == 'u')
		hex = "0123456789ABCDEF";
	else
		return ;
	if (n >= 16)
		dec_to_hex(n / 16, c);
	if (n < 16 && c == 'p')
	{
		ft_putstr_fd("0x", 1);
	}
	ft_putchar_fd(hex[n % 16], 1);
}

void	ft_put_uint(unsigned int n)
{
	if (n >= 10)
		ft_put_uint(n / 10);
	ft_putchar_fd((n % 10 + '0'), 1);
}
void	create_str(char c, va_list *args)
{
	if (c == 'c')
		ft_putchar_fd((char) va_arg(*args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(*args, char *), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*args, int), 1);
	else if (c == 'p')
		dec_to_hex(va_arg(*args, unsigned long), 'p');
	else if (c == 'u')
		ft_put_uint(va_arg(*args, unsigned int));
	else if (c == 'x')
		dec_to_hex(va_arg(*args, unsigned int), 'l');
	else if (c == 'X')
		dec_to_hex(va_arg(*args, unsigned int), 'u');
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else
		return ;
}
