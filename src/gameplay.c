/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:13:35 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/04 17:56:34 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	go_up(t_data *data)
{
	if (data->map.map_file [data->map.spawn_y - 1][data->map.spawn_x] == 'E'
		&& data->map.count_collectable == 0)
		win_screen(data);
	if (data->map.map_file[data->map.spawn_y - 1][data->map.spawn_x] != '1')
	{
		if (data->map.map_file[data->map.spawn_y - 1][data->map.spawn_x] == 'C')
		{
			data->map.count_collectable -= 1;
			data->map.map_file[data->map.spawn_y - 1][data->map.spawn_x] = '0';
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (data->map.spawn_x * 32),
			((data->map.spawn_y--) * 32));
		data->move += 1;
		ft_printf("Moves = %d\n", data->move);
		put_string(data);
	}
	change_sprite(data);
}

void	go_left(t_data *data)
{
	if (data->map.map_file [data->map.spawn_y][data->map.spawn_x - 1] == 'E' &&
		data->map.count_collectable == 0)
		win_screen(data);
	if (data->map.map_file[data->map.spawn_y][data->map.spawn_x - 1] != '1')
	{
		if (data->map.map_file[data->map.spawn_y][data->map.spawn_x - 1] == 'C')
		{
			data->map.count_collectable -= 1;
			data->map.map_file[data->map.spawn_y][data->map.spawn_x - 1] = '0';
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, ((data->map.spawn_x--) * 32),
			((data->map.spawn_y) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character2.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		data->move += 1;
		data->allow_sprite = 1;
		put_string(data);
		ft_printf("Moves = %d\n", data->move);
	}
}

void	go_down(t_data *data)
{
	if (data->map.map_file [data->map.spawn_y + 1][data->map.spawn_x] == 'E'
		&& data->map.count_collectable == 0)
		win_screen(data);
	if (data->map.map_file[data->map.spawn_y + 1][data->map.spawn_x] != '1')
	{
		if (data->map.map_file[data->map.spawn_y + 1][data->map.spawn_x] == 'C')
		{
			data->map.count_collectable -= 1;
			data->map.map_file[data->map.spawn_y + 1][data->map.spawn_x] = '0';
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (data->map.spawn_x * 32),
			((data->map.spawn_y++) * 32));
		data->move += 1;
		ft_printf("Moves = %d\n", data->move);
		put_string(data);
	}
	change_sprite(data);
}

void	go_right(t_data *data)
{
	if (data->map.map_file [data->map.spawn_y][data->map.spawn_x + 1] == 'E'
		&& data->map.count_collectable == 0)
		win_screen(data);
	if (data->map.map_file[data->map.spawn_y][data->map.spawn_x + 1] != '1')
	{
		if (data->map.map_file[data->map.spawn_y][data->map.spawn_x + 1] == 'C')
		{
			data->map.count_collectable -= 1;
			data->map.map_file[data->map.spawn_y][data->map.spawn_x + 1] = '0';
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, ((data->map.spawn_x++) * 32),
			((data->map.spawn_y) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character1.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		data->move += 1;
		data->allow_sprite = 0;
		put_string(data);
		ft_printf("Moves = %d\n", data->move);
	}
}

void	change_sprite(t_data *data)
{
	if (data->allow_sprite == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character1.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character2.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
}
