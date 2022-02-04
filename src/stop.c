/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:29 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 12:19:55 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	stop_1(char *err_msg)
{
	printf("Error\n%s\n", err_msg);
	exit (1);
}

int	stop_2(char *err_msg, t_data *data)
{
	free(data->map);
	printf("Error\n%s\n", err_msg);
	exit (1);
}

int	stop_3(char *err_msg, t_data *data)
{
	int	i;

	i = -1;
	while (data->map->map[++i])
		free(data->map->map[i]);
	free(data->map->map[i]);
	free(data->map->map);
	free(data->map);
	printf("Error\n%s\n", err_msg);
	exit (1);
}

int	stop_4(char *err_msg, t_data *data)
{
	int	i;

	i = -1;
	while (data->map->map[++i])
		free(data->map->map[i]);
	free(data->map->map[i]);
	free(data->map->map);
	free(data->map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	if (err_msg)
	{
		printf("Error\n%s\n", err_msg);
		exit (1);
	}
	exit(0);
}
