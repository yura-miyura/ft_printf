/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:01 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/25 16:41:19 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	int		dash;
	int		zero;
	int		precision;
	int		hash;
	int		space;
	int		plus;
	int		width;
	char	specifier;
}				t_format;

// put.c
int	put_char(char c, t_format *data);
int	put_str(char *str, t_format *data);


// data collection
const char	*collect_data(const char *str, t_format *f);
void	create_format(t_format *f);

// utils
int	padding(char c, int size);

int	convert(va_list *args, t_format *data);
int	ft_printf(const char *str, ...);

#endif
