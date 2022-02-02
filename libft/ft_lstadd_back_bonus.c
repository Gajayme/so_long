/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:01:07 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/13 14:53:49 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_copy;

	lst_copy = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (lst_copy -> next)
			lst_copy = lst_copy -> next;
		lst_copy->next = new;
	}
}
