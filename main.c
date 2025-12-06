#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int i1 =  ft_printf("%e\n", -1);
	int i2 = printf("%e\n", -1);
	printf("i1: %i, i2: %i", i1, i2);
}
