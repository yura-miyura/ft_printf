/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:54:34 by yartym            #+#    #+#             */
/*   Updated: 2026/01/27 14:34:28 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned long n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	dec_to_hex(unsigned long n, char c)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (c == 'X')
		base_hex = "0123456789ABCDEF";
	if (n >= 16)
		dec_to_hex(n / 16, c);
	ft_putchar_fd(base_hex[n % 16], 1);
}

int	space_plus_minus(int n, t_format *data)
{
	int i;

	i = 0;
	if (n >= 0 && (data->plus || data->space))
	{
		if (data->plus)
			ft_putchar_fd('+', 1);
		else
			ft_putchar_fd(' ', 1);
		i = 1;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		i = 1;
	}
	return (i);
}

int	hex_prefix(t_format *data)
{
	char	*prefix;
	char	c;
	int		add;

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

void	put_num_pos(int n)
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
