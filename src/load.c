/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:44:41 by lsouquie          #+#    #+#             */
/*   Updated: 2023/05/04 18:55:51 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	load(t_data *data)
{
	load_img(data);
	load_img2(data);
	load_img3(data);
}

void	load_img(t_data *data)
{
	data->sprites.floor.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/grass.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
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
}

void	load_img2(t_data *data)
{
		data->sprites.character1.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/character1.xpm",
			&data->sprites.character1.width,
			&data->sprites.character1.height);
		data->sprites.character2.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/character2.xpm",
			&data->sprites.character2.width,
			&data->sprites.character2.height);
}

void	load_img3(t_data *data)
{
	data->sprites.tree1.img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./Sprites/Tree_1.xpm", &data->sprites.tree1.width,
			&data->sprites.tree1.height);
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
