/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:13:32 by lyubov            #+#    #+#             */
/*   Updated: 2022/01/30 16:38:19 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	pre_left(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y][data->map->hero_x - 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
		move_left(data);
	return (0);
}

int	pre_down(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y + 1][data->map->hero_x];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
		move_down(data);
	return (0);
}

int	pre_right(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y][data->map->hero_x + 1];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
		move_right(data);
	return (0);
}

int	pre_up(t_data *data)
{
	char	c;

	c = data->map->map[data->map->hero_y - 1][data->map->hero_x];
	if ((c != '1' && c != 'E') || (c == 'E' && data->map->collect == 0))
		move_up(data);
	return (0);
}
