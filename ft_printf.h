/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 08:48:03 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/11/23 08:48:46by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

void	create_str(char c, va_list *args);
int		ft_printf(const char *str, ...);
void	dec_to_hex(unsigned long n, char c);
void	ft_put_uint(unsigned int n);

#endif
