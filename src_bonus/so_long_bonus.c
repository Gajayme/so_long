/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:57:07 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 17:53:34 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

//check leacks

int	img_open(t_data *data)
{
	data->floor_img = mlx_xpm_file_to_image(data->mlx,
			"img/floor.XPM", &data->img_w, &data->img_h);
	data->wall_img = mlx_xpm_file_to_image(data->mlx,
			"img/wall.XPM", &data->img_w, &data->img_h);
	data->hero_st_img = mlx_xpm_file_to_image(data->mlx,
			"img/hero.XPM", &data->img_w, &data->img_h);
	data->hero_img = data->hero_st_img;
	data->hero_mv_1_img = mlx_xpm_file_to_image(data->mlx,
			"img/hero_mv_1.XPM", &data->img_w, &data->img_h);
	data->hero_mv_2_img = mlx_xpm_file_to_image(data->mlx,
			"img/hero_mv_2.XPM", &data->img_w, &data->img_h);
	data->end_img = mlx_xpm_file_to_image(data->mlx,
			"img/end.XPM", &data->img_w, &data->img_h);
	data->collect_img = mlx_xpm_file_to_image(data->mlx,
			"img/collect.XPM", &data->img_w, &data->img_h);
	data->enemy_l_img = mlx_xpm_file_to_image(data->mlx,
			"img/enemy_l.XPM", &data->img_w, &data->img_h);
	data->enemy_r_img = mlx_xpm_file_to_image(data->mlx,
			"img/enemy_r.XPM", &data->img_w, &data->img_h);
	data->enemy_img = data->enemy_r_img;
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
	data->hero_step = 0;
	data->enemy_r = 0;
	data->enemy_l = 0;
	read_initer(filename, data);
	data->mlx = mlx_init();
	img_open(data);
	win_size(data);
	load_nums_img(data);
	enemy_spawn(data);
	data->mlx_win = mlx_new_window(data->mlx, data->win_w,
			data->win_h, "So_long");
	map_drawer(data);
	return (0);
}

int	fname_val(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (!filename || len <= 4 || ft_strncmp(filename + len - 4, ".ber", 4))
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2)
		stop("Invalid number of arguments", &data);
	if (fname_val(av[1]))
		stop("Invalid map", &data);
	game_initer(av[1], &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_rel, &data);
	mlx_hook(data.mlx_win, 17, 0, red_cross, &data);
	mlx_loop(data.mlx);
	return (0);
}
