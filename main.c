#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int main(void)
{
	char *t = "hello";
	int n1 = printf("|%05w|\n");
	int n2 = ft_printf("|%05w|\n");
	printf("1: %i, 2: %i\n", n1, n2);
}
