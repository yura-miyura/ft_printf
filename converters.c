/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:47:23 by yartym            #+#    #+#             */
/*   Updated: 2026/01/25 16:40:35 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// void	dec_to_hex(unsigned long n, t_format *data)
// {
// 	char *hex;
// 	char c;
//
// 	c = data->specifier;
// 	if (c == 'x' || c == 'p')
// 		hex = "0123456789abcdef";
// 	else if (c == 'x')
// 		hex = "0123456789abcdef";
// 	else
// 		return;
// 	if (n >= 16)
// 		dec_to_hex(n / 16, data);
// 	ft_putchar_fd(hex[n % 16], 1);
// 	(data->counter)++;
// }
//
// void	ft_puthex_prefix(t_format *data)
// {
// 	char	*prefix;
// 	char	c;
// 	int		add;
//
// 	add = 0;
// 	prefix = NULL;
// 	c = data->specifier;
// 	if ((data->hash && c == 'x') || c == 'p')
// 	{
// 		prefix = "0x"; add = 2;
// 	}
// 	else if (data->hash && c == 'X')
// 	{
// 		prefix = "0x";
// 		add = 2;
// 	}
// 	ft_putstr_fd(prefix, 1);
// 	data->counter += add;
// }
//
// void	ft_put_pointer(unsigned long number, t_format *data)
// {
// 	if (number > 0)
// 	{
// 		ft_puthex_prefix(data);
// 		dec_to_hex(number, data);
// 	}
// 	else
// 		ft_putnil(data);
// }
