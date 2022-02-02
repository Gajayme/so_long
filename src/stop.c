/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:29 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 20:21:29 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	wrapper(int func, char *err_txt, t_data *data)
{
	if (func == -1)
		stop(err_txt, data);
	return (func);
}

int	stop(char *err_msg, t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		if (data->map->map)
		{
			while (data->map->map[i])
			{
				free(data->map->map[i]);
				i += 1;
			}
			free(data->map->map);
		}
		if (data->map->file)
			free(data->map->file);
		free(data->map);
		if (data->mlx_win)
			mlx_destroy_window(data->mlx, data->mlx_win);
	}
	if (err_msg && printf("Error\n%s\n", err_msg))
		exit (1);
	exit (0);
}
