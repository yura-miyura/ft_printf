/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 08:51:33 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/30 07:55:29 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_char_in_set(char c, char const *set)
{
	int	i;
	int	is_in;

	is_in = 0;
	i = 0;
	while (set[i] && !is_in)
		if (c == set[i++])
			is_in = 1;
	return (is_in);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		start;
	int		end;
	int		sub_size;

	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && is_char_in_set(s1[start], set))
		start++;
	while (end >= 0 && end >= start && is_char_in_set(s1[end], set))
		end--;
	sub_size = end - start + 1;
	new = malloc(sizeof (char) * (sub_size + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, s1 + start, sub_size);
	new[sub_size] = '\0';
	return (new);
}
