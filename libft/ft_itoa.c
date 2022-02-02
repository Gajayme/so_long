/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:00:58 by gajayme           #+#    #+#             */
/*   Updated: 2021/10/20 16:51:41 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	itoa_abs(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

static char	*recursion(char *ptr, int n)
{
	if (n / 10)
		ptr = recursion(ptr, n / 10);
	else if (n < 0)
		*ptr++ = '-';
	*ptr++ = itoa_abs(n % 10) + '0';
	*ptr = '\0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		len;
	int		n_copy;
	char	*ptr;

	len = 0;
	n_copy = n;
	if (n <= 0)
		len = 1;
	while (n_copy)
	{
		n_copy /= 10;
		len += 1;
	}
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	else
		recursion(ptr, n);
	return (ptr);
}
