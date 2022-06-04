/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:41:47 by lyubov            #+#    #+#             */
/*   Updated: 2022/06/04 15:57:43 by lyubov           ###   ########.fr       */
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

void	line_counter(t_data *data)
{
	int	lines;

	lines = 0;
	while (data->map->map[lines] && data->map->map[lines + 1])
		lines ++;
	if (lines < 2 || ft_strlen(data->map->map[lines]) < 3)
		stop_3("Invalid map", data);
}


int	map_parse(t_data *data)
{
	int	h;

	h = -1;
	data->map->map = ft_split(data->map->file, '\n');
	free(data->map->file);
	data->map->file = NULL;
	if (!data->map->map)
		stop_2("Splitting error", data);
	line_counter(data);
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
	if (data->map->start != 1 || data->map->collect == 0
			|| data->map->end == 0)
			stop_3("Invalid map", data);
	return (0);
}
