/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:10:19 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 17:53:25 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

char	*gnl_strjoin(char **s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s2[0])
		return (*s1);
	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	ptr = (char *)malloc(s1_len + s2_len + 1);
	if (!ptr)
		return (NULL);
	ft_memmove(ptr, *s1, s1_len);
	ft_memmove(ptr + s1_len, s2, s2_len);
	ptr[s1_len + s2_len] = '\0';
	if (*s1)
		free(*s1);
	return (ptr);
}

int	file_read(char *filename, t_data *data)
{
	int		fd;
	int		ret;
	char	buf[1024 + 1];

	fd = wrapper(open(filename, O_RDONLY), "can't open map file", data);
	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, &buf, 1024);
		if (ret == -1)
		{
			free(data->map->file);
			data->map->file = NULL;
			close(fd);
			stop("Can't read from file", data);
		}
		buf[ret] = '\0';
		data->map->file = gnl_strjoin(&data->map->file, buf);
	}
	close(fd);
	return (0);
}

int	read_initer(char *filename, t_data *data)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		stop("Can't malloc", data);
	data->map->file = (char *)malloc(sizeof(char));
	if (!data->map->file)
		stop("Cant malloc", data);
	data->map->width = 0;
	data->map->height = 0;
	data->map->start = 0;
	data->map->end = 0;
	data->map->collect = 0;
	file_read(filename, data);
	map_parse(data);
	return (0);
}
