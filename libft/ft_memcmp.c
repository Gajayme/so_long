/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:25 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/13 16:15:20 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	long int	rez;

	i = 0;
	rez = 0;
	while (n--)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
		{
			rez = *((unsigned char *)s1 + i)
				- *((unsigned char *)s2 + i);
			return (rez);
		}
		i += 1;
	}
	return (rez);
}
