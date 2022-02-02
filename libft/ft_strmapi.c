/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:04:33 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/08 14:04:34 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;
	char	*copy;

	if (!f || !s)
		return (NULL);
	copy = (char *)s;
	ptr = (char *)malloc(ft_strlen(copy) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (copy[i])
	{
		ptr[i] = f(i, copy[i]);
		i += 1;
	}
	ptr[i] = '\0';
	return (ptr);
}
