#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int i1 = ft_printf("1: %%\n");
	int i2 = printf("2: %%\n");
	printf("i1: %i, i2: %i", i1, i2);
}
