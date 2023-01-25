/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:30 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/24 19:42:12 by lsouquie         ###   ########.fr       */
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
# include "./Libft/libft.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

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
	t_img	character;
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

/* Map utils 2*/
int		count(const char *a);
char	**copy_tab(char **dest, char **src, t_data *data);
void	*free_tab(char **res, size_t i, t_data *data, int allowfree);

/* Algo Map */
void	check_accessibility(t_data *data);
int		found_spawn(char **tab, t_data *data);
void	found_path(t_data *data, char **tab, int i, int j);

/* Rendering */

void	rendering(t_data *data);
void	load_img(t_data *data);
void	render_map(t_data *data);
void	render_object(t_data *data);

/* Gameplay */

int		gameplay(t_data *data);
void	go_up(t_data *data);
void	go_down(t_data *data);
void	go_right(t_data *data);
void	go_left(t_data *data);

/* events*/

int		keybinding(int keysim,t_data *data);
int		escape_manage(int keysim, t_data *data);
int		cross_manage(t_data *data);

int	handle_keypress(int keysym, t_data *data);

#endif