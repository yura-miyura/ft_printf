#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// char *t = NULL;
	int n = -42;
	int n1 = printf("|%15.10u|\n", n);
	int n2 = ft_printf("|%15.10u|\n", n);
	printf("1 %i, 2: %i\n", n1, n2);
}
