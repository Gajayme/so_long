/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:30 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:54:17 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	inc;

	if (!dest || !src)
		return (NULL);
	if (n == 0)
		return (dest);
	i = 0;
	inc = 1;
	if (src < dest)
	{
		inc = -1;
		i = n - 1;
	}
	while (n--)
	{
		*((char *)dest + i) = *((char *)src + i);
		i += inc;
	}
	return (dest);
}
