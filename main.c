#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// char *t = NULL;
	int n1 = printf("|%15.13i|\n", 0);
	int n2 = ft_printf("|%15.13i|\n", 0);
	printf("1 %i, 2: %i\n", n1, n2);
}
