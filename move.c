/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:13:35 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/25 10:49:39 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up(t_data *data)
{
	if (data->map.map_file[data->map.spawn_y - 1][data->map.spawn_x] != '1')
	{
		if (data->map.map_file[data->map.spawn_y - 1][data->map.spawn_x] == 'C')
			data->map.count_collectable -= 1;
		data->map.map_file[data->map.spawn_y][data->map.spawn_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (data->map.spawn_x * 32),
			((data->map.spawn_y--) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		// printf("%d", data->map.count_collectable);

	}
}

void	go_left(t_data *data)
{
	if (data->map.map_file[data->map.spawn_y][data->map.spawn_x - 1] != '1')
	{
		if (data->map.map_file[data->map.spawn_y][data->map.spawn_x - 1] == 'C')
			data->map.count_collectable -= 1;
		data->map.map_file[data->map.spawn_y][data->map.spawn_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, ((data->map.spawn_x--) * 32),
			((data->map.spawn_y) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		// printf("%d", data->map.count_collectable);
	}
}

void	go_down(t_data *data)
{
	if (data->map.map_file[data->map.spawn_y + 1][data->map.spawn_x] != '1')
	{
		if (data->map.map_file[data->map.spawn_y + 1][data->map.spawn_x] == 'C')
			data->map.count_collectable -= 1;
		data->map.map_file[data->map.spawn_y][data->map.spawn_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, (data->map.spawn_x * 32),
			((data->map.spawn_y++) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		// printf("%d", data->map.count_collectable);
	}
}

void	go_right(t_data *data)
{
	if (data->map.map_file[data->map.spawn_y][data->map.spawn_x + 1] != '1')
	{
		if (data->map.map_file[data->map.spawn_y][data->map.spawn_x + 1] == 'C')
			data->map.count_collectable -= 1;
		data->map.map_file[data->map.spawn_y][data->map.spawn_x] = '0';
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.floor.img, ((data->map.spawn_x++) * 32),
			((data->map.spawn_y) * 32));
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.character.img, (data->map.spawn_x * 32),
			((data->map.spawn_y) * 32));
		printf("%d", data->map.count_collectable);
		// if (data->map.count_collectable == 0)
		// {
		// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		// 		data->sprites.exit.img, (data->map.exit_x * 32),
		// 		(data->map.exit_y * 32));
		// }
	}
}
