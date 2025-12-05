/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 07:36:45 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/27 08:50:51 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	size;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len;
	new_str = malloc(sizeof (char) * size + 1);
	if (!new_str)
		return (NULL);
	new_str[size] = '\0';
	while (size-- > 0)
	{
		if (s2_len-- > 0)
			new_str[size] = s2[s2_len];
		else if (s1_len-- > 0)
			new_str[size] = s1[s1_len];
	}
	return (new_str);
}
