/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 22:41:02 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 20:18:47 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	red_cross(t_data *data)
{
	stop(NULL, data);
	return (0);
}

int	key_rel(int keycode, t_data *data)
{
	if (keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 13)
	{
		data->hero_img = data->hero_st_img;
		mlx_clear_window(data->mlx, data->mlx_win);
		map_drawer(data);
		movement_drawer(data);
	}
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 0)
		pre_left(data);
	if (keycode == 1)
		pre_down(data);
	if (keycode == 2)
		pre_right(data);
	if (keycode == 13)
		pre_up(data);
	if (keycode == 53)
		stop(NULL, data);
	return (0);
}
