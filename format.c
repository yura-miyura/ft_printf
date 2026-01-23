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

#incldue "ft_printf.h"

t_format	*create_t_format(void)
{
	t_format *f;

	f->dash = 0;
	f->zero= 0;
	f->persision = -1;
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

int is_dash_zero_dot(char *s, t_format *f)
{
	char	c;

	c = *s;
	if (c == '-')
	{
		if (ft_isdigit(*(++s))
			f->dash = ft_atoi(s);
		else
			f->dash = 1;
	}
	else if (c == '0')
	{
		if (ft_isdigit(*(++s))
			f->zero= ft_atoi(s);
		else
			f->zero = 1;
	}
	else if (c == '.')
	{
		if (ft_isdigit(*(++s))
			f->presision = ft_atoi(s);
		else
			f->presision = 0;
	}
	else
		return (0)
	return (c);
}

int	is_hash_space_plus(char c, t_format *f)
{
	if (c == '#')
		f->hash = 1;
	else if (c == ' ')
		f->space = 1;
	else if (c == '+')
		f->plus = 1;
	else
		return (0);
	return (c);
}
