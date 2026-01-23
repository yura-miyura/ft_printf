/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuriiartymicloud.com <yuriiartymicloud.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:32:37 by yuriiartymi       #+#    #+#             */
/*   Updated: 2025/10/29 09:18:25 by yuriiartymi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Add to the front of the list
void	ft_lstadd_front(t_list **lst, t_list *new_n)
{
	new_n->next = *lst;
	*lst = new_n;
}
