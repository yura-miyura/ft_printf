#include "ft_printf.h"
#include "libft/libft.h"

void	dec_to_hex(unsigned long n,char c, t_printf *data)
{
	char *hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (n >= 16)
		dec_to_hex(n / 16, c, data);
	ft_putchar_fd(hex[n % 16], 1);
	(data->counter)++;
}

void	ft_put_pointer(unsigned long number, t_printf *data)
{
	if (number > 0)
	{
		ft_putstr_fd("0x", 1);
		data->counter += 2;
		dec_to_hex(number, 'x', data);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		data->counter += 5;
	}
}
