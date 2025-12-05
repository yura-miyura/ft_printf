/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:33:24 by yartym            #+#    #+#             */
/*   Updated: 2025/10/30 10:29:28 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	full_size;
	size_t	j;
	size_t	i;

	j = ft_strnlen(dst, size);
	full_size = ft_strlen(src);
	if (j == size)
		return (full_size + size);
	full_size += j;
	i = 0;
	while (j < size - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (full_size);
}
