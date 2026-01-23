/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yartym <yartym@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:47:23 by yartym            #+#    #+#             */
/*   Updated: 2026/01/23 14:47:30 by yartym           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void dec_to_hex(unsigned long n, t_format *data) {
  char *hex;
  char c;

  c = data->specifier;
  if (c == 'x' || c == 'p')
    hex = "0123456789abcdef";
  else if (c == 'x')
    hex = "0123456789abcdef";
  else
    return;
  if (n >= 16)
    dec_to_hex(n / 16, data);
  if (data->precision == -1 || (data->precision) > 0) {
    ft_putchar_fd(hex[n % 16], 1);
    (data->precision)--;
    (data->counter)++;
  }
}

void ft_put_pointer(unsigned long number, t_format *data) {
  if ()
    if (number > 0) {
      ft_putstr_fd("0x", 1);
      data->counter += 2;
      dec_to_hex(number, data);
    } else {
      ft_putstr_fd("(nil)", 1);
      data->counter += 5;
    }
}
