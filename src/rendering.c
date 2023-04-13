/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/13 14:22:43 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	rendering(t_data *data)
{
	long	i;
	int	x;
	int	y;
	int	curr_sprite;
	

	i = 0;
	x = 0;
	curr_sprite = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			animation(curr_sprite, y, x, data);
			// while (i < 1000000)
			// 	i++;
			curr_sprite = (curr_sprite + 1) % 4;
			y++;
		}
	x++;
	}
	return (1);
}

void	animation(int i, int y, int x, t_data *data)
{

	(void)i;
	if (data->map.map_file[y][x] == '1')
	{
		// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		// 		data->sprites.tree1.img, (x * 32), (y * 32));
		anim_tree(i, y, x, data);
	}
}

void	anim_tree(int i, int y, int x, t_data *data)
{
	// if (i == 0)
	// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
	// 		data->sprites.tree1.img, (x * 32), (y * 32));
	if (i == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree2.img, (x * 32), (y * 32));
	else if (i == 2)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree3.img, (x * 32), (y * 32));
	else if (i == 3)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.tree4.img, (x * 32), (y * 32));
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
			// if (data->map.map_file[y][x] == '1')
			// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			// 		data->sprites.tree1.img, (x * 32), (y * 32));
			if (data->map.map_file[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->sprites.floor.img, (x * 32), (y * 32));
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

