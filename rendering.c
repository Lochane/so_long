/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/25 10:46:14 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering(t_data *data)
{
	load_img(data);
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
	y = 0;
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
					data->sprites.character.img, (x * 32), (y * 32));
			y++;
		}
		x++;
	}
}

void	load_img(t_data *data)
{
	data->sprites.floor.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/floor.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	data->sprites.wall.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/walls.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	data->sprites.collectable.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/collectible.xpm",
			&data->sprites.collectable.width,
			&data->sprites.collectable.height);
	data->sprites.character.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/Umiside.xpm", &data->sprites.character.width,
			&data->sprites.character.height);
			data->sprites.exit.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/exit.xpm", &data->sprites.exit.width,
			&data->sprites.exit.height);
}
