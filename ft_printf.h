/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:01 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/12/05 17:00:03 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	size_t	dash;
	size_t	zero;
	int		persicion;
	size_t	hash;
	size_t	space;
	size_t	plus;
	char	specifier;

	size_t	counter;
}				t_format;

int	convert(char c, va_list *args);
int	ft_printf(const char *str, ...);

#endif
