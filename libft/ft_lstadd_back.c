/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:58:40 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/29 09:13:44 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add to the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new_n)
{
	t_list	*node;

	if (*lst == NULL)
		*lst = new_n;
	else
	{
		node = ft_lstlast(*lst);
		node->next = new_n;
	}
}
