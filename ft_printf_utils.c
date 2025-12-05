/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:14:38 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/12/05 16:59:33 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	dec_to_hex(unsigned long n, char c, int *count)
{
	char	*hex;

	if (c == 'x' || c == 'p')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		return ;
	if (n >= 16)
		dec_to_hex(n / 16, c, count);
	if (n < 16 && c == 'p')
	{
		ft_putstr_fd("0x", 1);
		*count += 2;
	}
	ft_putchar_fd(hex[n % 16], 1);
	(*count)++;
}

static void	ft_put_uint(unsigned int n, int *count)
{
	if (n >= 10)
		ft_put_uint(n / 10, count);
	ft_putchar_fd((n % 10 + '0'), 1);
	(*count)++;
}

int	convert(char c, va_list *args)
{
	char	*str;
	int		n;

	n = 0;
	if (c == 'c' || c == '%')
	{
		ft_putchar_fd(c, 1);
		n++;
	}
	else if (c == 's' || c == 'd' || c == 'i')
	{
		if (c == 's')
			str = va_arg(*args, char *);
		else
			str = ft_itoa(va_arg(*args, int));
		ft_putstr_fd(str, 1);
		n = ft_strlen(str);
	}
	else if (c == 'p')
		dec_to_hex(va_arg(*args, unsigned long), 'p', &n);
	else if (c == 'u')
		ft_put_uint(va_arg(*args, unsigned int), &n);
	else if (c == 'x' || c == 'X')
		dec_to_hex(va_arg(*args, unsigned int), c, &n);
	return (n);
}
