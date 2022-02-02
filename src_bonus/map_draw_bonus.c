/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 19:08:38 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 17:53:19 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	img_drawer(char c, t_data *data, int i, int j)
{
	if (c == '1' )
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->wall_img, j * data->img_w, i * data->img_h);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->floor_img, j * data->img_w, i * data->img_h);
	else if (c == 'C' && img_drawer('0', data, i, j))
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->collect_img, j * data->img_w, i * data->img_h);
	else if (c == 'P' && img_drawer('0', data, i, j))
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->hero_img, j * data->img_w, i * data->img_h);
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->end_img, j * data->img_w, i * data->img_h);
	else if (c == '!' && img_drawer('0', data, i, j))
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->enemy_img, j * data->img_w, i * data->img_h);
	return (1);
}

int	space_checker(t_data *data)
{
	data->up_draw_start = data->map->hero_y;
	data->left_draw_start = data->map->hero_x;
	if (data->up_draw_start > 7)
		data->up_draw_start = 7;
	if (data->left_draw_start > 9)
		data->left_draw_start = 9;
	data->left_draw_start = data->map->hero_x - data->left_draw_start;
	data->up_draw_start = data->map->hero_y - data->up_draw_start;
	data->right_draw_start = data->map->width - (data->map->hero_x + 1);
	data->down_draw_start = data->map->height - (data->map->hero_y + 1);
	while (data->left_draw_start > 0 && data->right_draw_start < 10)
	{
		data->left_draw_start -= 1;
		data->right_draw_start += 1;
	}
	while (data->up_draw_start > 0 && data->down_draw_start < 7)
	{
		data->up_draw_start -= 1;
		data->down_draw_start += 1;
	}
	return (0);
}

int	map_drawer(t_data *data)
{
	int	i;
	int	j;
	int	x;

	space_checker(data);
	i = -1;
	while (data->map->map[data->up_draw_start] && ++i < MAX_WIN_H / data->img_h)
	{
		j = -1;
		x = data->left_draw_start;
		while (data->map->map[data->up_draw_start][x]
				&& ++j < MAX_WIN_W / data->img_w)
		{
			img_drawer(data->map->map[data->up_draw_start][x], data, i, j);
			x += 1;
		}
		data->up_draw_start += 1;
	}
	return (0);
}
