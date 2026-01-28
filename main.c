#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	char *t = NULL;
	int n1 = printf("|%.5s|\n", t);
	int n2 = ft_printf("|%.5s|\n", t);
	printf("1: %i, 2: %i\n", n1, n2);
}
