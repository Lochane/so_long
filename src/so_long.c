/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:46:51 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:57 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"	

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		exit(0);
	data = malloc(sizeof(t_data));
	if (!data)
		exit(0);
	initialise_struct(data);
	validate_mapfile(argc, argv[1], data);
	parsing_map(argv[1], data);
	so_long(data);
	free(data);
	return (0);
}


void	so_long(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_tab(data->map.map_file, data->map.map_height, data, 1);
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map.map_widht * 32),
			((data->map.map_height * 32) + 10), "So_long");
	if (!data->win_ptr)
	{
		free_tab(data->map.map_file, data->map.map_height, data, 1);
		free(data->mlx_ptr);
		exit(EXIT_FAILURE);
	}
	load(data);
	render_basegame(data);
	mlx_hook(data->win_ptr, 33, 1L << 17, &quit_game, data);
	mlx_key_hook(data->win_ptr, &keybinding, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_loop_hook(data->mlx_ptr, &render_character, data);
	mlx_loop_hook(data->mlx_ptr, &render_anim, data);
	mlx_loop(data->mlx_ptr);
}

