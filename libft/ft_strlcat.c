/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:06 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:55:34 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	len;

	len = maxlen;
	srclen = ft_strlen(src);
	while (*dst != '\0' && len != 0)
	{
		dst++;
		len --;
	}
	dstlen = maxlen - len;
	if (maxlen == dstlen)
		return (dstlen + srclen);
	else
	{
		if (srclen < ((maxlen - dstlen) - 1))
			ft_memcpy(dst, src, srclen + 1);
		else
		{
			ft_memcpy(dst, src, ((maxlen - dstlen) - 1));
			dst[maxlen - dstlen - 1] = '\0';
		}
	}
	return (dstlen + srclen);
}
