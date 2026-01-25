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
	int			count;
	va_list		args;
	t_format	*data;

	count = 0;
	data = NULL;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			str = collect_data(str, data);
			if (data->specifier)
				count += convert(&args, data);
 		}
		else
		{
			ft_putchar_fd(*str, 1);
			count++;
		}
		str++;
	}
	return (count);
}
