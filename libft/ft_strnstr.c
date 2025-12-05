/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:40:43 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 11:22:14 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Original function doesn't throught the error when the haystack
or needle is NULL. I've also deleted this error check */
// if (!haystack || !needle)
//		return (NULL);
// Search for a substring within a string of a certain length.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*trun_hay;

	if (!haystack && !len)
		return (NULL);
	trun_hay = (char *) haystack;
	i = 0;
	if (!needle[i])
		return (trun_hay);
	while (trun_hay[i] && i < len)
	{
		if (trun_hay[i] == *needle)
		{
			j = 0;
			while (trun_hay[i + j] && needle[j]
				&& trun_hay[i + j] == needle[j] && i + j < len)
				j++;
			if (!needle[j])
				return (trun_hay + i);
		}
		i++;
	}
	return (NULL);
}
