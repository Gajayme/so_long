/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:03:03 by gajayme           #+#    #+#             */
/*   Updated: 2021/12/25 00:55:00 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ram_freeer(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i += 1;
	}
	free (ptr);
}

static size_t	word_count(char *ptr, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (ptr[i])
	{
		if (ptr[i] != c)
			words += 1;
		while (ptr[i] != c && ptr[i])
			i += 1;
		if (ptr[i])
			i += 1;
	}
	return (words);
}

static int	letter_filler(char *s_ptr, char **ptr, size_t i, size_t j)
{
	size_t	k;
	size_t	h;

	k = 0;
	h = 0;
	while (ptr[k] != NULL)
		k += 1;
	ptr[k] = (char *)malloc((j + 1) * sizeof(char));
	if (!ptr[k])
		return (0);
	while (j > 0)
	{
		ptr[k][h] = s_ptr[i - j];
		h += 1;
		j -= 1;
	}
	ptr[k][h] = '\0';
	return (1);
}

static int	word_filler(char *s_ptr, char **ptr, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s_ptr[i])
	{
		if (s_ptr[i] != c)
		{
			j = 0;
			while (s_ptr[i] != c && s_ptr[i])
			{
				i += 1;
				j += 1;
			}
			if (letter_filler(s_ptr, ptr, i, j) == 0)
				return (0);
		}
		if (s_ptr[i])
			i += 1;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	*s_ptr;
	char	**ptr;

	if (!s)
		return (NULL);
	s_ptr = (char *)s;
	ptr = (char **)ft_calloc((word_count(s_ptr, c) + 1), sizeof(char *));
	if (!ptr)
		return (NULL);
	if (word_filler(s_ptr, ptr, c) == 0)
		ram_freeer(ptr);
	return (ptr);
}
