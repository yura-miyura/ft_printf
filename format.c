/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 07:17:15 by yartym            #+#    #+#             */
/*   Updated: 2026/01/23 07:17:35 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_format	*create_t_format(void)
{
	t_format *f;

	f->dash = 0;
	f->zero= 0;
	f->precision = -1;
	f->hash= 0;
	f->space= 0;
	f->plus = 0;
	f->specifier = 0;

	return (f);
}

int	is_specifier(char c)
{
	char *specifiers;

	specifiers = "cspiduxX%";
	while (*specifiers)
		if (c == *(specifiers++))
			return (c);
	return (0);
}

int	is_flag(char c, t_format *f)
{
	if (c == '-')
		f->dash = 1;
	else if (c == '0')
		f->zero = 1;
	else if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
	else
		return (0);
	return (c);
}

t_format	*collect_data(char *str)
{
	t_format *f;

	f = create_t_format();
	while (is_flag(*str, f))
		str++;
	while (ft_isdigit(*str))
		f->width  = f->width * 10 + *str++ - '0';
	if (*str++ == '.')
		f->precision = 0;
	while (ft_isdigit(*str))
		f->precision = f->precision * 10 + *str++ - '0';
	if (is_specifier(*str))
		f->specifier = *str;
	return (f);
}
