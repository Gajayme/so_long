/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:40 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:41 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		k;
	char		*ptr;

	ptr = (char *)haystack;
	k = ft_strlen(needle);
	if (*needle == 0)
		return (ptr);
	while (*ptr != '\0')
	{
		if (ft_memcmp(ptr, needle, k) == 0)
			return (ptr);
		if (len == 0)
			return (NULL);
		len -= 1;
		ptr += 1;
		if (len < 1 || k > len)
			return (NULL);
	}
	return (NULL);
}
