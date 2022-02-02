/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:38 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:55:16 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	return (ft_memmove(ptr, s, ft_strlen(s) + 1));
}
