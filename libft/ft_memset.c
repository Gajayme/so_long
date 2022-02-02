/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:02:37 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:45:35 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memset(void *memptr, int val, size_t num)
{
	char	*str;

	str = memptr;
	while (num--)
	{
		*str = (char)val;
		str ++;
	}
	return (memptr);
}
