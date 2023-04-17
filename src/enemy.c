/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 00:23:40 by lochane           #+#    #+#             */
/*   Updated: 2023/04/17 15:52:44 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	enemy(t_data *data)
{
	data->time.anim_speed++;
	printf("%d\n", data->time.anim_speed);
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
	long			i;

	x = 0;
	while (x < data->map.map_widht)
	{
		y = 1;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '*')
			{
				i = 0;
				if (data->map.map_file[y - 1][x] != '1')
				{
					sprites(data, x, y, 0);
					break ;
				}
				else
				{
					data->allow = 1;
					break ;
				}
				y = 1;
			}
			y++;
		}
		x++;
	}
}

void	enemy_down(t_data *data)
{
	int				x;
	int				y;
	long i;

	x = 0;
	while (x < data->map.map_widht)
	{
		y = 1;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '*')
			{
				i = 0;
				if (data->map.map_file[y + 1][x] != '1')
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
			y++;
		}
	x++;
	}
}

void	sprites(t_data *data, int x, int y, int allow)
{
	int k;

	k = 0;
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
	while (k != 6)
	{
		if (data->map.map_file[k][x] == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.floor.img, (x * 32),
				(k * 32));
		if (data->map.map_file[k][x] == '*')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->sprites.enemy1.img, (x * 32),
				(k * 32));
		if (data->map.map_file[k][x] == '1')
			printf("");
		k++;
	}
}