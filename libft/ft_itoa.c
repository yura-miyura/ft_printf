/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:27:01 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 07:59:24 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	n_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	put_numbers(int n, char *n_str, int n_len)
{
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			n_str[--n_len] = '8';
			n /= 10;
		}
		n *= -1;
		n_str[0] = '-';
	}
	if (n >= 10)
		put_numbers(n / 10, n_str, n_len - 1);
	n_str[n_len - 1] = n % 10 + '0';
}

// Returns int as a stirng
char	*ft_itoa(int n)
{
	size_t	size;
	char	*n_str;

	size = n_len(n);
	n_str = malloc(sizeof (char) * size + 1);
	if (!n_str)
		return (NULL);
	put_numbers(n, n_str, size);
	n_str[size] = '\0';
	return (n_str);
}

/* #include <stdio.h>
int	main(void)
{
	char *str = ft_itoa(-2147483648);
	printf("%s\n", str);
	free(str);
} */
