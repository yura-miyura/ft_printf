/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:13:17 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/25 16:44:47 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_format	*data;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			data = collect_data(str, &i);
			count += convert(&args, data);
			free(data);
 		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

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
		n = put_d_i(va_arg(*args, int), data);
	else if (c == 'u')
		n = put_u(va_arg(*args, unsigned int), data);
	else if (c == 'p')
		n = put_pointer(va_arg(*args, unsigned long), data);
	else if (c == 'x' || c == 'X')
		n = put_hex(va_arg(*args, unsigned int), data);
	else if (c == '%')
		n = put_char('%', data);
	else
		n = put_char(c, data);
	return (n);
}
