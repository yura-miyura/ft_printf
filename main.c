#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *s = "hello";

	int n1 = printf("|%10.3s|\n", s);
	int n2 = ft_printf("|%10.3s|\n", s);
	printf("1 %i, 2: %i\n", n1, n2);
}
