/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:55 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:56:11 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*src_ptr;
	char	*dst_ptr;
	size_t	s_len;
	size_t	src_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start || len == 0)
		return (ft_strdup(""));
	src_ptr = (char *)s + start;
	src_len = ft_strlen(src_ptr);
	if (len < src_len)
		dst_ptr = (char *)malloc(len + 1);
	else
		dst_ptr = (char *)malloc(src_len);
	if (!dst_ptr)
		return (NULL);
	if (len > src_len)
		ft_memmove(dst_ptr, src_ptr, src_len);
	else
		ft_memmove(dst_ptr, src_ptr, len);
	dst_ptr[len] = '\0';
	return (dst_ptr);
}
