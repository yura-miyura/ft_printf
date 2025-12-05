/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 08:30:12 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/26 08:57:37 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(s1) + 1;
	new_str = malloc(sizeof (char) * size);
	if (!new_str)
		return (NULL);
	while (size-- > 0)
		new_str[size] = s1[size];
	return (new_str);
}
