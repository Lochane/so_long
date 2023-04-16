/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:23:40 by lochane           #+#    #+#             */
/*   Updated: 2023/04/16 11:52:35 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	enemy(t_data *data)
{
	int				x;
	int				y;

	x = 0;
	data->map.e1_bool = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{

			if (data->map.map_file[y][x] == '*' && data->map.e1_bool == 0)
				e1_up(data, y, x);
			if (data->map.map_file[y][x] == '*' && data->map.e1_bool == 1)
				e1_down(data, y, x);			
			y++;
		}
	x++;
	}
	return (10);
}

void	e1_up(t_data *data, int x, int y)
{
	
	if (data->map.map_file[y - 1][x] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (x * 32),
			(y * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.enemy1.img, (x * 32),
			((y - 1) * 32));
	}
	else
		data->map.e1_bool = 1;
}

void	e1_down(t_data *data, int x, int y)
{
	
	if (data->map.map_file[y + 1][x] != '1')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (x * 32),
			(y * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.enemy1.img, (x * 32),
			((y + 1) * 32));
	}
	else
		data->map.e1_bool = 0;
}