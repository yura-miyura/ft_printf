/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:47:05 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/29 14:38:29by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		str_len;

	i = 0;
	str_len = 0;
	va_list	args;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			create_str(str[++i], &args);
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	return (str_len);
}
