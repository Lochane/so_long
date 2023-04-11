/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:19:20 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/11 18:40:53 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	rendering(t_data *data)
{
	
	render_map(data);
	// animation(data);
	render_object(data);
	return (10);
}

void	render_map(t_data *data)
{
	int	x;
	int	y;
	int	curr_sprite;
	long long i;

	x = 0;
	y = 0;
	i = 0;
	curr_sprite = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '1')
			{
				if (curr_sprite == 0)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree1.img, (x * 32), (y * 32));
						printf("%d\n", curr_sprite);

				}	
				else if (curr_sprite == 1)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree2.img, (x * 32), (y * 32));
						printf("%d\n", curr_sprite);
					
				}

				else if (curr_sprite == 2)
				{
					
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree3.img, (x * 32), (y * 32));
						printf("%d\n", curr_sprite);
				}

				else if (curr_sprite == 3)
				{
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.floor.img, (x * 32), (y * 32));
						printf("%d\n", curr_sprite);
					
				}

			i = 0;
			while (i < 10000)
				i++;
			curr_sprite = (curr_sprite + 1) % 4;	
			}
				// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				// 	data->sprites.tree1.img, (x * 32), (y * 32));
		
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

void	load_img(t_data *data)
{
	data->sprites.floor.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/grass.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	data->sprites.tree1.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/Tree_1.xpm", &data->sprites.tree1.width,
			&data->sprites.tree1.height);
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
	/*-----------------------------------*/
	data->sprites.tree2.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "Sprites/Tree_2.xpm",
			&data->sprites.tree2.width,
			&data->sprites.tree2.height);
	data->sprites.tree3.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "Sprites/Tree_3.xpm",
			&data->sprites.tree3.width,
			&data->sprites.tree3.height);
	data->sprites.tree4.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "Sprites/Tree_4.xpm",
			&data->sprites.tree4.width,
			&data->sprites.tree4.height);
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

int	animation(t_data *data)
{
	int		curr_sprite;
	int	x;
	int	y;
	int i;

	x = 0;
	i = 0;
	curr_sprite = 0;
		x = 0;
	while (x < data->map.map_widht)
	{
		y = 0;
		while (y < data->map.map_height)
		{
			if (data->map.map_file[y][x] == '1')
			{
				if (curr_sprite == 0)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree1.img, (x * 32), (y * 32));
				else if (curr_sprite == 1)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree2.img, (x * 32), (y * 32));
				else if (curr_sprite == 2)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree3.img, (x * 32), (y * 32));
				else if (curr_sprite == 3)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
						data->sprites.tree4.img, (x * 32), (y * 32));
				i = 0;
				while (i < 1000000)
					i++;
			curr_sprite = (curr_sprite + 1) % 4;
			}
			y++;
		}
		x++;
	}
	return (1);
}