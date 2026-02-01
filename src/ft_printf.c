/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:51:48 by yartym            #+#    #+#             */
/*   Updated: 2026/01/29 09:51:50 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;
	t_format	data;
	int			add;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		add = 1;
		if (str[i] == '%')
		{
			parse_format(str, &i, &data);
			add = convert(&args, &data);
		}
		else
			ft_putchar_fd(str[i], 1);
		count += add;
		i++;
	}
	va_end(args);
	return (count);
}

int	convert(va_list *args, t_format *data)
{
	int		n;
	char	c;

	n = 1;
	c = data->specifier;
	if (c == 'c')
		n = put_char(va_arg(*args, int), data);
	else if (c == 's')
		n = put_str(va_arg(*args, char *), data);
	else if (is_d_i(data))
		n = put_number(va_arg(*args, int), data);
	else if (c == 'u' || is_x(data))
		n = put_number(va_arg(*args, unsigned int), data);
	else if (c == 'p')
		n = put_pointer(va_arg(*args, unsigned long), data);
	else if (c == '%')
		n = put_char('%', data);
	else
		ft_putchar_fd('%', 1);
	return (n);
}
