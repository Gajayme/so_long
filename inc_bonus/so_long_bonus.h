/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyubov <lyubov@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:03:25 by lyubov            #+#    #+#             */
/*   Updated: 2022/02/02 20:16:12 by lyubov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	int		enemy_x;
	int		enemy_y;

}				t_map;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;

	int		win_w;
	int		win_h;
	int		img_w;
	int		img_h;

	void	*floor_img;
	void	*wall_img;
	void	*hero_img;
	void	*hero_st_img;
	void	*hero_mv_1_img;
	void	*hero_mv_2_img;
	void	*enemy_img;
	void	*enemy_r_img;
	void	*enemy_l_img;
	void	*end_img;
	void	*collect_img;

	void	*img_0;
	void	*img_1;
	void	*img_2;
	void	*img_3;
	void	*img_4;
	void	*img_5;
	void	*img_6;
	void	*img_7;
	void	*img_8;
	void	*img_9;

	int		up_draw_start;
	int		left_draw_start;
	int		down_draw_start;
	int		right_draw_start;

	int		enemy_r;
	int		enemy_l;
	int		hero_step;
	int		movement;
	t_map	*map;
}				t_data;

//FUNCS

//exits
int		wrapper(int func, char *err_txt, t_data *data);
int		stop(char *err_msg, t_data *data);

//map read
char	*gnl_strjoin(char **s1, char const *s2);
int		file_read(char *filename, t_data *data);
int		read_initer(char *file, t_data *data);

//map parse
int		line_counter(t_data *data);
int		mdl(char *line, t_data *data, int h);
int		map_parse(t_data *data);
int		fst_lst(char *line, t_data *data, char flag);

//map draw
int		space_checker(t_data *data);
int		img_open(t_data *data);
int		img_drawer(char c, t_data *data, int i, int j);
int		map_drawer(t_data *data);

//animation
int		change_skin(t_data *data);

//movements
int		movements(t_data *data);
int		load_nums_img(t_data *data);
int		movement_drawer(t_data *data);
int		num_draw(char num, t_data *data, int start_x);

//move
int		pre_right(t_data *data);
int		pre_left(t_data *data);
int		pre_up(t_data *data);
int		pre_down(t_data *data);
int		move_right(t_data *data, char c);
int		move_left(t_data *data, char c);
int		move_up(t_data *data, char c);
int		move_down(t_data *data, char c);

//enemyes
int		enemy_spawn(t_data *data);
int		enemy_move(t_data *data);

//hooks
int		key_hook(int keycode, t_data *data);
int		key_rel(int keycode, t_data *data);
int		enemy_loop(t_data *data);
int		red_cross(t_data *data);

#endif
