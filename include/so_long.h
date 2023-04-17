/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:30 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/17 15:14:41 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>
# include "struct.h"
# include "./Minilibx/mlx.h"
# include "./libft/libft.h"

void	so_long(t_data *data);

/* Map fonction */
void	validate_mapfile(int argc, char *mapfile, t_data *data);
void	parsing_map(char *mapfile, t_data *data);
void	check_mapsize(t_data *data);
void	map_to_tab(char *mapfile, t_data *data);
void	check_mapintegrity(t_data *data);

/* Utils */
void	validate_chars(t_data *data, char c);
int		count_line(char *mapfile, t_data *data);
void	error_msg(char *msg, int tofree, t_data *data);
void	error_char(t_data *data);
void	initialise_struct(t_data *data);

/* Utils 2*/
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

int		rendering(t_data *data);
void	animation(int y, int x, t_data *data);
void	anim_tree(int y, int x, t_data *data);
void	render_basegame(t_data *data);


/* Gameplay */

void	go_up(t_data *data);
void	go_down(t_data *data);
void	go_right(t_data *data);
void	go_left(t_data *data);
void	change_sprite(t_data *data);


/* Events */

int		keybinding(int keysim, t_data *data);
int		handle_keypress(int keysym, t_data *data);
void	check_fin(t_data *data);
int		quit_game(t_data *data);
void	win_screen(t_data *data);

/* Load */
void	load(t_data *data);
void	load_img(t_data *data);
void	load_img2(t_data *data);
void	load_img3(t_data *data);

/* Enemy */

int		enemy(t_data *data);
void	enemy_up(t_data *data);
void	enemy_down(t_data *data);
void	sprites(t_data *data, int x, int y, int allow);


#endif