#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *s;

	s = NULL;

	int n1 = printf(NULL);
	int n2 = ft_printf(NULL);
	printf("1: %i, 2: %i\n", n1, n2);
}
