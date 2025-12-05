/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:33:59 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 10:22:16 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//Doesn't catch dst as a NULL
// if (!dst)
// 		return (NULL);
// Copies memmory addres to the new dst
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dst_tmp;
	const unsigned char	*src_tmp;

	if (!dst && !src)
		return (NULL);
	dst_tmp = dst;
	src_tmp = src;
	while (n--)
		*dst_tmp++ = *src_tmp++;
	return (dst);
}
