/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:13:17 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/28 08:58:21 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_format	data;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			parse_format(str, &i, &data);
			count += convert(&args, &data);
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
	else if (is_d_i(data))
		n = put_number(va_arg(*args, int), data);
	else if (c == 'u' || is_x_X(data))
		n = put_number(va_arg(*args, unsigned int), data);
	else if (c == 'p')
		n = put_pointer(va_arg(*args, unsigned long), data);
	else if (c == '%')
		n = put_char('%', data);
	else
		n = put_char(c, data);
	return (n);
}
