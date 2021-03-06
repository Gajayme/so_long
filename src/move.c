/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:43:39 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 11:48:38 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	movements(t_data *data)
{
	data->movement += 1;
	printf("Movements: %d\n", data->movement);
	return (1);
}

int	move_right(t_data *data)
{
	if (data->map->map[data->map->hero_y][data->map->hero_x + 1] == 'C')
		data->map->collect -= 1;
	else if (data->map->map[data->map->hero_y][data->map->hero_x + 1] == 'E')
		stop_4(NULL, data);
	data->map->map[data->map->hero_y][data->map->hero_x + 1] = 'P';
	data->map->map[data->map->hero_y][data->map->hero_x] = '0';
	data->map->hero_x += 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	map_drawer(data);
	movements(data);
	return (0);
}

int	move_left(t_data *data)
{
	if (data->map->map[data->map->hero_y][data->map->hero_x - 1] == 'C')
		data->map->collect -= 1;
	else if (data->map->map[data->map->hero_y][data->map->hero_x - 1] == 'E')
		stop_4(NULL, data);
	data->map->map[data->map->hero_y][data->map->hero_x - 1] = 'P';
	data->map->map[data->map->hero_y][data->map->hero_x] = '0';
	data->map->hero_x -= 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	map_drawer(data);
	movements(data);
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map->map[data->map->hero_y - 1][data->map->hero_x] == 'C')
		data->map->collect -= 1;
	else if (data->map->map[data->map->hero_y - 1][data->map->hero_x] == 'E')
		stop_4(NULL, data);
	data->map->map[data->map->hero_y - 1][data->map->hero_x] = 'P';
	data->map->map[data->map->hero_y][data->map->hero_x] = '0';
	data->map->hero_y -= 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	map_drawer(data);
	movements(data);
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map->map[data->map->hero_y + 1][data->map->hero_x] == 'C')
		data->map->collect -= 1;
	else if (data->map->map[data->map->hero_y + 1][data->map->hero_x] == 'E')
		stop_4(NULL, data);
	data->map->map[data->map->hero_y + 1][data->map->hero_x] = 'P';
	data->map->map[data->map->hero_y][data->map->hero_x] = '0';
	data->map->hero_y += 1;
	mlx_clear_window(data->mlx, data->mlx_win);
	map_drawer(data);
	movements(data);
	return (0);
}
