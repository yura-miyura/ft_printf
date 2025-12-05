#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("1: %i, %c, %x, %%, %s, %p\n", -1, 'a', -123, "hello", "hello");
	printf("2: %i, %c, %x, %%, %s, %p\n", -1, 'a', -123, "hello", "hello");
}
