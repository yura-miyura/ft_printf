/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 09:14:27 by yartym            #+#    #+#             */
/*   Updated: 2026/01/29 09:14:29 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_type_number(long n, t_format *data)
{
	if (!is_zero_with_flags(n, data))
	{
		if (is_d_i(data))
			print_int_pos(n);
		else if (is_x(data))
			print_hex(n, data->specifier);
		else if (data->specifier == 'u')
			print_uint(n);
	}
}

void	print_hex(unsigned long n, char c)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (c == 'X')
		base_hex = "0123456789ABCDEF";
	if (n >= 16)
		print_hex(n / 16, c);
	ft_putchar_fd(base_hex[n % 16], 1);
}

void	print_uint(unsigned int n)
{
	if (n >= 10)
		print_uint(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void	print_int_pos(int n)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			ft_putstr_fd("2147483648", 1);
			return ;
		}
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, 1);
	ft_putchar_fd((n % 10 + '0'), 1);
}
