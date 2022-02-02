/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:16 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/08 14:05:43 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((char *)arr + i) == (char)c)
			return ((char *)arr + i);
		i += 1;
	}
	return (NULL);
}
