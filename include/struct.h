/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 23:36:35 by lochane           #+#    #+#             */
/*   Updated: 2023/02/20 12:17:45 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	int			stop;
	t_sprite	sprites;
	t_map		map;
}			t_data;

#endif