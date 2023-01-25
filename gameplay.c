/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:24:55 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/24 19:30:05 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	gameplay(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, &cross_manage, data);
	mlx_key_hook(data->win_ptr, &keybinding, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
	return (0);
}