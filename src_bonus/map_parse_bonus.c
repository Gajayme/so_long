/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:41:47 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 12:12:21 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	fst_lst(char *line, t_data *data, char flag)
{
	int	i;

	i = 0;
	if (flag == 'f')
	{
		while (line[i])
		{
			if (line[i] != '1')
				stop_3("Invalid map", data);
			i += 1;
		}
		data->map->width = i;
		return (0);
	}
	while (line[i])
	{
		if (line[i] != '1')
			stop_3("Invalid map", data);
		i += 1;
	}
	if (i != data->map->width)
		stop_3("Invalid map", data);
	return (0);
}

int	mdl(char *line, t_data *data, int h)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if ((i == 0 && line[0] != '1') || (!line[i + 1] && line[i] != '1'))
			stop_3("Invalid map", data);
		else if (line[i] == 'P')
		{
			data->map->start += 1;
			data->map->hero_x = i;
			data->map->hero_y = h;
		}
		else if (line[i] == 'E')
			data->map->end += 1;
		else if (line[i] == 'C')
			data->map->collect += 1;
		else if (line[i] == 'F')
			data->map->enemy += 1;
		else if (line[i] != '0' && line[i] != '1')
			stop_3("Invalid map", data);
	}
	if (i != data->map->width)
		stop_3("Invalid map", data);
	return (0);
}

int	line_counter(t_data *data)
{
	int	i;
	int	lines;

	i = -1;
	lines = 0;
	while (data->map->file[++i])
	{
		if (data->map->file[i] == '\n')
			lines += 1;
	}
	return (lines);
}

int	map_parse(t_data *data)
{
	int	h;
	int	lines;

	h = -1;
	lines = line_counter(data);
	data->map->map = ft_split(data->map->file, '\n');
	free(data->map->file);
	data->map->file = NULL;
	if (!data->map->map)
		stop_2("Splitting error", data);
	while (data->map->map[++h])
	{
		if (h == 0)
			fst_lst(data->map->map[h], data, 'f');
		else if (!data->map->map[h + 1])
			fst_lst(data->map->map[h], data, 'l');
		else
			mdl(data->map->map[h], data, h);
	}
	data->map->height = h;
	if (h < 3 || data->map->width < 3 || data->map->start
		!= 1 || data->map->collect == 0 || data->map->end == 0
		|| lines != h)
		stop_3("Invalid map", data);
	return (0);
}
