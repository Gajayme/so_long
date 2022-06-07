/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 11:59:24 by lyubov            #+#    #+#             */
/*   Updated: 2022/06/07 17:17:30 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	enemy_right(t_data	*data, int i)
{
	if (data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i] + 1] == 'P')
		stop_4(NULL, data);
	data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '0';
	data->map->enemy_x[i] += 1;
	data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '>';
	return (1);
}

int	enemy_left(t_data	*data, int i)
{
	if (data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i] - 1] == 'P')
		stop_4(NULL, data);
	data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '0';
	data->map->enemy_x[i] -= 1;
	data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '<';
	return (1);
}

int	enemy_move(t_data *data)
{
	char	next;
	char	cur;
	int		i;

	i = -1;
	while (++i != data->map->enemy_amount)
	{
		cur = data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]];
		if (cur == '>')
		{
			next = data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i] + 1];
			if (next != '1' && next != 'E' && next != 'C' && enemy_right(data, i))
				continue;
			else
				data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '<';
		}
		else if (cur == '<'){
			next = data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i] - 1];
			if (next != '1' && next != 'E' && next != 'C' && enemy_left(data, i))
				continue;
			else
				data->map->map[data->map->enemy_y[i]][data->map->enemy_x[i]] = '>';
		}
	}
	return (0);
}

int	enemy_spawn(t_data *data)
{
	int	amount;
	int	i;
	int	j;
	int r_h;

	amount = data->map->height / 4;
	if (!amount)
		return 0;
	data->map->enemy_x = (int *)malloc(sizeof(int) * data->map->enemy_amount);
	if (!data->map->enemy_x)
		stop_3("Malloc error\n", data);
	data->map->enemy_y = (int *)malloc(sizeof(int) * data->map->enemy_amount);
	if (!data->map->enemy_y ){
		free(data->map->enemy_y);
		stop_3("Malloc error\n", data);
	}
	j = -1;
	while (--amount >= 0)
	{
		r_h = rand() % data->map->height;
		i = -1;
		while (++i < data->map->width)
		{
			if (data->map->map[r_h][i] == '0')
				{
					data->map->map[r_h][i] = '>';
					data->map->enemy_x[++j] = i;
					data->map->enemy_y[j] = r_h;
					data->map->enemy_amount ++;
					break;
				}
		}
	}
	return (0);
}
