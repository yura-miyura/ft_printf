/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 17:00:01 by yuriiartymi       #+#    #+#             */
/*   Updated: 2026/01/27 14:27:53 by yartym           ###   ########.fr       */
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

// put
int	put_char(char c, t_format *data);
int	put_str(char *str, t_format *data);
int	put_pointer(unsigned long n, t_format *data);
int	put_d_i(int n, t_format *data);
int	put_u(unsigned int n, t_format *data);


// data collection
t_format	*collect_data(const char *str, int *i);
t_format	*create_format(void);

// padding
int		zero_padding(int len, int width, t_format *data);
int		width_padding(int width, t_format *data);
int		dash_padding(int width, t_format *data);
int		padding(char c, int size);

// utils
void	dec_to_hex(unsigned long n, char c);
int		space_plus_minus(int n, t_format *data);
int		hex_prefix(t_format *data);
int		hex_len(unsigned long n);
void	put_int_pos(int n);
int		int_len(int n);
int		u_int_len(unsigned int n);
void	put_u_int(unsigned int n);

int	convert(va_list *args, t_format *data);
int	ft_printf(const char *str, ...);

#endif
