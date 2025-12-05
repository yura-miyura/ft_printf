/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:07:37 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 09:50:48 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Doesn't catch segmentation fault when s == NULL
// if (!s)
// 		return (NULL);
// Returns location of the character in memory address
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;
	unsigned char	cc;

	i = 0;
	cc = c;
	temp_s = (unsigned char *) s;
	while (i < n)
	{
		if (*(temp_s + i) == cc)
			return ((void *)(temp_s + i));
		i++;
	}
	return (NULL);
}
