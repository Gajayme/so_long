/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:07 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 21:23:15 by gajayme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	img_open(t_data *data)
{
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"img/floor.XPM", &data->img_w, &data->img_h);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"img/wall.XPM", &data->img_w, &data->img_h);
	data->hero_img = mlx_xpm_file_to_image(data->mlx,
			"img/hero.XPM", &data->img_w, &data->img_h);
	data->end_img = mlx_xpm_file_to_image(data->mlx,
			"img/end.XPM", &data->img_w, &data->img_h);
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			"img/collect.XPM", &data->img_w, &data->img_h);
	return (0);
}

int	win_size(t_data *data)
{
	data->win_w = data->img_w * data->map->width;
	data->win_h = data->img_h * data->map->height;
	if (data->win_w > MAX_WIN_W)
		data->win_w = MAX_WIN_W;
	if (data->win_h > MAX_WIN_H)
		data->win_h = MAX_WIN_H;
	return (0);
}

int	game_initer(char *filename, t_data *data)
{
	data->movement = 0;
	read_initer(filename, data);
	data->mlx = mlx_init();
	img_open(data);
	win_size(data);
	data->mlx_win = mlx_new_window(data->mlx, data->win_w,
			data->win_h, "so_long");
	map_drawer(data);
	return (0);
}

int	fname_val(char *filename)
{
	int	len;
	int	fd;

	len = ft_strlen(filename);
	if (!filename || len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4))
		return (1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	close (fd);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2)
		stop_1("Invalid number of arguments");
	if (fname_val(av[1]))
		stop_1("Invalid file");
	game_initer(av[1], &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx_win, 17, 0, red_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
