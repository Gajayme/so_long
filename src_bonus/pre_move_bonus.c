/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_move_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:13:32 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 17:53:32 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	change_skin(t_data *data)
{
	if (data->hero_step == 0)
	{
		data->hero_img = data->hero_mv_1_img;
		data->hero_step += 1;
	}
	else if (data->hero_step == 1)
	{
		data->hero_img = data->hero_mv_2_img;
		data->hero_step = 0;
	}
	return (0);
}

int	pre_left(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y][data->map->hero_x - 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
	{
		change_skin(data);
		move_left(data, c);
	}
	return (0);
}

int	pre_down(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y + 1][data->map->hero_x];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
	{
		change_skin(data);
		move_down(data, c);
	}
	return (0);
}

int	pre_right(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y][data->map->hero_x + 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
	{
		change_skin(data);
		move_right(data, c);
	}
	return (0);
}

int	pre_up(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y - 1][data->map->hero_x];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
	{
		change_skin(data);
		move_up(data, c);
	}
	return (0);
}
