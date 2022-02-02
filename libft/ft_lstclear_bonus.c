/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:01:50 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/13 15:17:07 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp_2;

	if (!(*lst) || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		del(tmp->content);
		tmp_2 = tmp->next;
		free(tmp);
		tmp = tmp_2;
	}
	*lst = NULL;
}
