/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:06 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/13 14:05:32 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
			ft_lstclear(&new_lst, del);
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}
