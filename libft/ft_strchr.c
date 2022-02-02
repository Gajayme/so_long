/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:07 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:55:08 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int symbol)
{
	while (*string != (char)symbol && *string)
	{
		string++;
	}
	if (*string == '\0' && symbol != '\0')
		return (NULL);
	return ((char *)string);
}
