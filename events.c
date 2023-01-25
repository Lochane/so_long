/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:21:38 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/24 19:15:03 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.character.img);
		mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
		mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
		mlx_destroy_image(data->mlx_ptr, data->sprites.collectable.img);
		mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img);
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		if (data->mlx_ptr)
			mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_tab(data->map.map_file, data->map.map_height, data, 1);
		exit (0);
	}
	return (0);
}

int	cross_manage(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.character.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collectable.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data->map.map_file, data->map.map_height, data, 1);
	exit (0);
}

int	keybinding(int keysim, t_data *data)
{
	if (keysim == 'w' || keysim == 65362)
		go_up(data);
	if (keysim == 's' || keysim == 65364)
		go_down(data);
	if (keysim == 'd' || keysim == 65363)
		go_right(data);
	if (keysim == 'a' || keysim == 65361)
		go_left(data);
	return (0);
}