/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/16 00:27:05 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	rendering(t_data *data)
{
	int				x;
	int				y;

	x = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			animation(y, x, data);
			y++;
		}
	x++;
	}
	return (10);
}

void	animation( int y, int x, t_data *data)
{
	if (data->map.map_file[y][x] == '1')
		anim_tree(y, x, data);
}

void	anim_tree(int y, int x, t_data *data)
{
	data->time.anim_speed += 1;
	if (data->time.anim_speed >= 401000)
		data->time.anim_speed = 0;
	if (data->time.anim_speed >= 0 && data->time.anim_speed <= 100000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree1.img, (x * 32), (y * 32));
	else if (data->time.anim_speed >= 101000 && data->time.anim_speed <= 200000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree2.img, (x * 32), (y * 32));
	else if (data->time.anim_speed >= 201000 && data->time.anim_speed <= 300000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree3.img, (x * 32), (y * 32));
	else if (data->time.anim_speed >= 301000)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree4.img, (x * 32), (y * 32));

}

void	render_basegame(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.tree1.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.floor.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.collectable.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.character1.img, (x * 32), (y * 32));
			y++;
		}
		x++;
	}
}
