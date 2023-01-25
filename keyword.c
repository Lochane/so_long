/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyword.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 13:17:24 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/24 15:13:11 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	(void)data;
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_printf("Keypress: %d\n", keysym);
	exit (0);
}

int	cross_kill(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit (0);
}

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit (0);
}

int	mouse_position(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_printf("Mouse position is = %d\n");
	return (0);
}