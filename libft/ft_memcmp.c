/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:32:27 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 09:52:06 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Doesn't catch segmentation fault when s1 or s2 == NULL
// if (!n || !s1 || !s2)
// 		return (0);
// Compares two memmory addreses
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	if (!n)
		return (0);
	temp_s1 = (unsigned char *) s1;
	temp_s2 = (unsigned char *) s2;
	while (*temp_s1 == *temp_s2 && n > 1)
	{
		temp_s1++;
		temp_s2++;
		n--;
	}
	return ((unsigned char) *temp_s1 - (unsigned char) *temp_s2);
}
