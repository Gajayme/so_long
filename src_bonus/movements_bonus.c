/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:26:32 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/04 12:13:45 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc_bonus/so_long_bonus.h"

int	load_nums_img(t_data *data)
{
	data->img_0 = mlx_xpm_file_to_image(data->mlx,
			"num_img/0.XPM", &data->img_w, &data->img_h);
	data->img_1 = mlx_xpm_file_to_image(data->mlx,
			"num_img/1.XPM", &data->img_w, &data->img_h);
	data->img_2 = mlx_xpm_file_to_image(data->mlx,
			"num_img/2.XPM", &data->img_w, &data->img_h);
	data->img_3 = mlx_xpm_file_to_image(data->mlx,
			"num_img/3.XPM", &data->img_w, &data->img_h);
	data->img_4 = mlx_xpm_file_to_image(data->mlx,
			"num_img/4.XPM", &data->img_w, &data->img_h);
	data->img_5 = mlx_xpm_file_to_image(data->mlx,
			"num_img/5.XPM", &data->img_w, &data->img_h);
	data->img_6 = mlx_xpm_file_to_image(data->mlx,
			"num_img/6.XPM", &data->img_w, &data->img_h);
	data->img_7 = mlx_xpm_file_to_image(data->mlx,
			"num_img/7.XPM", &data->img_w, &data->img_h);
	data->img_8 = mlx_xpm_file_to_image(data->mlx,
			"num_img/8.XPM", &data->img_w, &data->img_h);
	data->img_9 = mlx_xpm_file_to_image(data->mlx,
			"num_img/9.XPM", &data->img_w, &data->img_h);
	return (0);
}

int	num_draw(char num, t_data *data, int x)
{
	if (num == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_0, x, 0);
	if (num == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_1, x, 0);
	if (num == '2')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_2, x, 0);
	if (num == '3')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_3, x, 0);
	if (num == '4')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_4, x, 0);
	if (num == '5')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_5, x, 0);
	if (num == '6')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_6, x, 0);
	if (num == '7')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_7, x, 0);
	if (num == '8')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_8, x, 0);
	if (num == '9')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_9, x, 0);
	return (0);
}

int	movement_drawer(t_data *data)
{
	int		i;
	int		x;
	char	*mov_arr;

	i = -1;
	x = 0;
	mov_arr = ft_itoa(data->movement);
	if (!mov_arr)
		stop_3("Itoa error", data);
	while (mov_arr[++i])
	{
		num_draw(mov_arr[i], data, x);
		x += data->img_w;
	}
	free(mov_arr);
	return (0);
}
