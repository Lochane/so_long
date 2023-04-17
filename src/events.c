/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:21:38 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/17 19:01:47 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit_game(data);
	return (0);
}

int	keybinding(int keysim, t_data *data)
{
	if (data->stop == 1)
	{
		if (keysim == 'w' || keysim == 65362)
			go_up(data);
		if (keysim == 's' || keysim == 65364)
			go_down(data);
		if (keysim == 'd' || keysim == 65363)
			go_right(data);
		if (keysim == 'a' || keysim == 65361)
			go_left(data);
		check_fin(data);
	}
	return (0);
}

void	check_fin(t_data *data)
{
	if (data->map.count_collectable == 0)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit.img, (data->map.exit_x * 32),
			(data->map.exit_y * 32));
	}
}

int	quit_game(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.end_screen.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.character1.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.character2.img);
	// mlx_destroy_image(data->mlx_ptr, data->sprites.character_right.img);
	// mlx_destroy_image(data->mlx_ptr, data->sprites.character_left.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collectable.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.tree1.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.tree2.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.tree3.img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.tree4.img);

	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->win_ptr2)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr2);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab(data->map.map_file, data->map.map_height, data, 1);
	exit (0);
}

void	win_screen(t_data *data)
{
	data->stop = 0;
	data->win_ptr2 = mlx_new_window(data->mlx_ptr, 1900, 729, "GG");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr2,
		data->sprites.end_screen.img, 0, 0);
	mlx_hook(data->win_ptr2, 17, 1L << 17, &quit_game, data);
	mlx_key_hook(data->win_ptr2, &keybinding, data);
	mlx_hook(data->win_ptr2, KeyPress, KeyPressMask, &handle_keypress, data);
}

void	lose_screen(t_data *data)
{
	data->stop = 1;
	data->win_ptr2 = mlx_new_window(data->mlx_ptr, 1900, 729, "GG");
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr2,
		data->sprites.end_screen.img, 0, 0);
	mlx_hook(data->win_ptr2, 17, 1L << 17, &quit_game, data);
	mlx_key_hook(data->win_ptr2, &keybinding, data);
	mlx_hook(data->win_ptr2, KeyPress, KeyPressMask, &handle_keypress, data);
}
