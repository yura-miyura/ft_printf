#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *t = NULL;
	int n1 = printf("|%-10p|\n", t);
	int n2 = ft_printf("|%-10p|\n", t);
	printf("1 %i, 2: %i\n", n1, n2);
}
