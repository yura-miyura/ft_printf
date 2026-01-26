#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *s = NULL;

	int n1 = printf("|%10.3p|\n", NULL);
	int n2 = ft_printf("|%10.3p|\n", s);
	printf("1 %i, 2: %i\n", n1, n2);
}
