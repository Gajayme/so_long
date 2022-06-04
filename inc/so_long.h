/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:03:25 by lyubov            #+#    #+#             */
/*   Updated: 2022/06/04 15:52:59 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX_WIN_W 800
# define MAX_WIN_H 600
# define UP			7
# define DOWN		7
# define LEFT		9
# define RIGHT		10

//libs
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

//structs
typedef struct s_map
{
	char	*file;
	char	**map;
	int		width;
	int		height;
	int		start;
	int		end;
	int		collect;
	int		enemy;
	int		hero_x;
	int		hero_y;

}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;

	int		win_w;
	int		win_h;

	void	*floor_img;
	void	*wall_img;
	void	*hero_img;
	void	*end_img;
	void	*collect_img;

	int		up_draw_start;
	int		left_draw_start;
	int		down_draw_start;
	int		right_draw_start;

	int		img_w;
	int		img_h;

	int		movement;
	t_map	*map;
}				t_data;

//FUNCS

//exits
int		stop_1(char *err_msg);
int		stop_2(char *err_msg, t_data *data);
int		stop_3(char *err_msg, t_data *data);
int		stop_4(char *err_msg, t_data *data);

//map read
char	*sl_strjoin(char *s1, char const *s2);
int		file_read(char *filename, t_data *data);
int		read_initer(char *file, t_data *data);

//map parse
int		map_parse(t_data *data);
void		line_counter(t_data *data);
int		mdl(char *line, t_data *data, int h);
int		fst_lst(char *line, t_data *data, char flag);

//map draw
int		space_checker(t_data *data);
int		img_open(t_data *data);
int		img_drawer(char c, t_data *data, int i, int j);
int		map_drawer(t_data *data);

//move
int		pre_right(t_data *data);
int		pre_left(t_data *data);
int		pre_up(t_data *data);
int		pre_down(t_data *data);
int		move_right(t_data *data);
int		move_left(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);

//hooks
int		key_hook(int keycode, t_data *data);
int		red_cross(t_data *data);

#endif
