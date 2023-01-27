/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:30 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/26 18:04:29 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "./Minilibx/mlx.h"
# include "./libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		linelenght;
	int		width;
	int		height;
	int		endian;
	char	*path;
}			t_img;

typedef struct s_sprite
{
	t_img	floor;
	t_img	wall;
	t_img	collectable;
	t_img	character_up;
	t_img	character_down;
	t_img	character_right;
	t_img	character_left;
	t_img	end_screen;
	t_img	exit;
}			t_sprite;

typedef struct s_map
{
	char	**map_file;
	int		map_height;
	int		map_widht;
	int		count_exit;
	int		count_collectable;
	int		count_spawn;
	int		exit_founded;
	int		collectable_founded;
	int		spawn_x;
	int		spawn_y;
	int		exit_x;
	int		exit_y;
}			t_map;

typedef struct s_data {
	void		*mlx_ptr;
	void		*win_ptr;
	void		*win_ptr2;
	int			move;
	t_sprite	sprites;
	t_map		map;
}			t_data;

void	so_long(t_data *data);

/* Map fonction */
void	validate_map(int argc, char *mapfile, t_data *data);
void	parsing_map(char *mapfile, t_data *data);
void	check_mapsize(t_data *data);
void	map_to_tab(char *mapfile, t_data *data);
void	check_mapintegrity(t_data *data);

/* Map utils */
void	validate_chars(t_data *data, char c);
int		count_line(char *mapfile, t_data *data);
void	error_msg(char *msg, int tofree, t_data *data);
void	error_char(t_data *data);
void	initialise_struct(t_data *data);

/* Map utils 2*/
int		count(const char *a);
void	copy_tab(char **dest, char **src, t_data *data);
void	*free_tab(char **res, size_t i, t_data *data, int allowfree);
int		found_exit(char **tab, t_data *data);
int		found_spawn(char **tab, t_data *data);

/* Algo Map */
void	check_accessibility(t_data *data);
char	found_path(t_data *data, char **tab);
char	fill_path(t_data *data, char **tab, int i, int j);
char	overflow(t_data *data, char **tab, int i, int j);

/* Rendering */

void	rendering(t_data *data);
void	load_img2(t_data *data);
void	load_img(t_data *data);
void	render_map(t_data *data);
void	render_object(t_data *data);

/* Gameplay */

void	go_up(t_data *data);
void	go_down(t_data *data);
void	go_right(t_data *data);
void	go_left(t_data *data);
void	print_move(t_data *data);

/* events*/

int		keybinding(int keysim, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	check_fin(t_data *data);
int		quit_game(t_data *data);
void	win_screen(t_data *data);

#endif