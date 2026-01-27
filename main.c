#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// char *t = NULL;
	int n = INT_MIN;
	int n1 = printf("|%1.1i|\n", n);
	int n2 = ft_printf("|%1.1i|\n", n);
	printf("1 %i, 2: %i\n", n1, n2);
}
