/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:17:15 by yartym            #+#    #+#             */
/*   Updated: 2026/01/28 09:44:21 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_format *f)
{
	ft_bzero(f,	sizeof(t_format));
	f->dash = 0;
	f->zero = 0;
	f->precision = -1;
	f->hash= 0;
	f->space= 0;
	f->plus = 0;
	f->width = 0;
	f->specifier = 0;
}

void	parse_format(const char *str, int *i, t_format *f)
{
	int		index;

	index = *i;
	reset_struct(f);
	while (is_flag(str[index], f))
		index++;
	while (ft_isdigit(str[index]))
		f->width  = f->width * 10 + str[index++] - '0';
	if (str[index] == '.')
	{
		index++;
		f->precision = 0;
		while (ft_isdigit(str[index]))
			f->precision = f->precision * 10 + str[index++] - '0';
	}
	f->specifier = str[index];
	*i = index;
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

