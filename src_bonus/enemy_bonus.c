/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:59:24 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 20:15:51 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	enemy_right(t_data	*data)
{
	data->enemy_img = data->enemy_r_img;
	if (data->map->map[data->map->enemy_y][data->map->enemy_x + 1] == 'P')
		stop_4(NULL, data);
	data->map->map[data->map->enemy_y][data->map->enemy_x] = '0';
	data->map->enemy_x += 1;
	data->map->map[data->map->enemy_y][data->map->enemy_x] = '!';
	return (1);
}

int	enemy_left(t_data	*data)
{
	data->enemy_img = data->enemy_l_img;
	if (data->map->map[data->map->enemy_y][data->map->enemy_x - 1] == 'P')
		stop_4(NULL, data);
	data->map->map[data->map->enemy_y][data->map->enemy_x] = '0';
	data->map->enemy_x -= 1;
	data->map->map[data->map->enemy_y][data->map->enemy_x] = '!';
	return (1);
}

int	enemy_move(t_data *data)
{
	char	r;
	char	l;

	r = data->map->map[data->map->enemy_y][data->map->enemy_x + 1];
	if (r != '1' && r != 'E' && r != 'C' && data->enemy_l != 1
		&& enemy_right(data))
		return (0);
	else
	{
		data->enemy_l = 1;
		data->enemy_r = 0;
	}
	l = data->map->map[data->map->enemy_y][data->map->enemy_x - 1];
	if (l != '1' && l != 'E' && l != 'C' && data->enemy_r != 1
		&& enemy_left(data))
		return (0);
	else
	{
		if (r != '1' && r != 'E' && r != 'C')
			enemy_right(data);
		data->enemy_l = 0;
		data->enemy_r = 1;
	}
	return (0);
}

int	enemy_spawn(t_data *data)
{
	int	amount;
	int	i;
	int	j;

	amount = 0;
	i = data->map->height / 2;
	while (data->map->map[i] && amount == 0)
	{
		j = 1;
		while (data->map->map[i][j] && amount == 0)
		{
			if (data->map->map[i][j] == '0' && data->map->map[i][j + 1] != 'P'
				&& data->map->map[i][j - 1] != 'P')
			{
				data->map->map[i][j] = '!';
				data->map->enemy_x = j;
				data->map->enemy_y = i;
				amount += 1;
			}
			j += 1;
		}
		i += 1;
	}
	return (0);
}
