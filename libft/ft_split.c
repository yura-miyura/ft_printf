/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:57:58 by yartym            #+#    #+#             */
/*   Updated: 2025/10/30 07:59:52 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		else if (i == 0 && s[i] != c)
			words++;
		i++;
	}
	return (words);
}

static int	fill_array(char	**strs, char const *s, char c, int words)
{
	int	start;
	int	end;
	int	word;

	start = 0;
	word = 0;
	while (word < words)
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		strs[word] = ft_substr(s, start, end - start);
		if (!strs[word])
			return (1);
		start = end;
		word++;
	}
	strs[word] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = malloc(sizeof (char *) * (words + 1));
	if (!strs)
		return (NULL);
	if (fill_array(strs, s, c, words))
	{
		free(strs);
		return (NULL);
	}
	return (strs);
}
