/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:23:40 by lochane           #+#    #+#             */
/*   Updated: 2023/04/20 12:23:04 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	enemy(t_data *data)
{
	if (data->stop == 0)
		return (0);
	data->time.anim_speed++;
	if (data->time.anim_speed % 10000 == 0)
	{
		if (data->allow == 1)
			enemy_down(data);
		if (data->allow == 0) 
			enemy_up(data);
	}
	if (data->time.anim_speed > 2147483640)
		data->time.anim_speed = 0;
	return (1);
}

void	enemy_up(t_data *data)
{
	int				x;
	int				y;

	x = -1;
	while (++x < data->map.map_widht)
	{
		y = 0;
		while (++y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '*')
			{
				if (data->map.map_file[y - 1][x] != '1' && data->map.map_file[y - 1][x] != 'C')
				{
					sprites(data, x, y, 0);
					break ;
				}
				else
				{
					data->allow = 1;
					break ;
				}
				y = 0;
			}
		}
	}
}

void	enemy_down(t_data *data)
{
	int				x;
	int				y;

	x = -1;
	while (++x < data->map.map_widht)
	{
		y = 0;
		while (++y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '*')
			{
				if (data->map.map_file[y + 1][x] != '1' && 
						data->map.map_file[y + 1][x] != 'C')
				{
					sprites(data, x, y, 1);
					break ;
				}
				else
				{
					data->allow = 0;
					break ;
				}
			}
		}
	}
}

void	sprites(t_data *data, int x, int y, int allow)
{
	int k;

	k = -1;
	if (x == data->map.spawn_x && y == data->map.spawn_y)
			lose_screen(data);
	if (x == data->map.spawn_x && y == data->map.spawn_y)
			lose_screen(data);
	update_map(data, x, y , allow);
	while (++k != 6)
	{
		if (data->map.map_file[k][x] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.floor.img, (x * 32),
				(k * 32));
		if (data->map.map_file[k][x] == '*')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.enemy1.img, (x * 32),
				(k * 32));
	}
}

void	update_map(t_data *data, int x, int y, int allow)
{
	if (allow == 0)
	{
		data->map.map_file[y][x] = '0';
		data->map.map_file[y - 1][x] = '*';
	}
	else
	{
		data->map.map_file[y][x] = '0';
		data->map.map_file[y + 1][x] = '*';
	}
}

void	lose_screen(t_data *data)
{
	data->stop = 0;
	data->win_ptr2 = mlx_new_window(data->mlx_ptr, 1900, 729, "GG");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr2,
		data->sprites.end_screen.img, 0, 0);
	mlx_hook(data->win_ptr2, 17, 1L << 17, &quit_game, data);
	mlx_key_hook(data->win_ptr2, &keybinding, data);
	mlx_hook(data->win_ptr2, KeyPress, KeyPressMask, &handle_keypress, data);
}