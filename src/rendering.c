/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/10 19:34:57 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	rendering(t_data *data)
{
	load_img(data);
	load_img2(data);
	render_map(data);
	render_object(data);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.wall.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] != '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.floor.img, (x * 32), (y * 32));
			y++;
		}
		x++;
	}
}

void	render_object(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.collectable.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.character_up.img, (x * 32), (y * 32));
			y++;
		}
		x++;
	}
}

void	load_img(t_data *data)
{
	data->sprites.floor.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/grass.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	data->sprites.wall.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/tree.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	data->sprites.collectable.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/collectable_1.xpm",
			&data->sprites.collectable.width,
			&data->sprites.collectable.height);
	data->sprites.exit.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/exit.xpm", &data->sprites.exit.width,
			&data->sprites.exit.height);
	data->sprites.end_screen.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "Sprites/endscreen.xpm",
			&data->sprites.end_screen.width,
			&data->sprites.end_screen.height);
}

void	load_img2(t_data *data)
{
	data->sprites.character_left.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/characterleft.xpm",
			&data->sprites.character_left.width,
			&data->sprites.character_left.height);
		data->sprites.character_up.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/characterup.xpm",
			&data->sprites.character_up.width,
			&data->sprites.character_up.height);
		data->sprites.character_down.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/characterdown.xpm",
			&data->sprites.character_down.width,
			&data->sprites.character_down.height);
			data->sprites.character_right.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/characterright.xpm",
			&data->sprites.character_right.width,
			&data->sprites.character_right.height);
}
