/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:01 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/28 10:56:54 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_format
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

// struct
void	parse_format(const char *str, int *i, t_format *f);
void	reset_struct(t_format *f);

//len
int		len_number(long n, t_format *data);
int		hex_len(unsigned long n);
int		int_len(int n);
int		u_int_len(unsigned int n);

// is
int		is_flag(char c, t_format *f);
int		is_d_i(t_format *data);
int		is_x(t_format *data);
int		is_space_plus_minus(int n, t_format *data);
int		is_zero_with_flags(long n, t_format *data);

//pnt
void	pnt_hex(unsigned long n, char c);
void	pnt_int_pos(int n);
void	pnt_uint(unsigned int n);
void	pnt_type_number(long n, t_format *data);

// put
int		put_char(char c, t_format *data);
int		put_str(char *str, t_format *data);
int		put_pointer(unsigned long n, t_format *data);
int		put_number(long n, t_format *data);

// padding
int		zero_padding(int len, int width, t_format *data);
int		width_padding(int width, t_format *data);
int		dash_padding(int width, t_format *data);
int		padding(char c, int size);

// utils
int		space_plus_minus(int n, t_format *data);
int		hex_prefix(t_format *data);

// main
int		convert(va_list *args, t_format *data);
int		ft_printf(const char *str, ...);

#endif
