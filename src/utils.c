/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:42 by lsouquie          #+#    #+#             */
/*   Updated: 2023/04/20 12:47:27 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	error_char(t_data *data)
{
	if (data->map.count_collectable == 0)
		error_msg("Error:\nToo few collectable\n", 1, data);
	if (data->map.count_exit > 1)
		error_msg("Error:\nToo many exit\n", 1, data);
	if (data->map.count_exit < 1)
		error_msg("Error:\nNo exit\n", 1, data);
	if (data->map.count_spawn > 1)
		error_msg("Error:\nToo many spawn\n", 1, data);
	if (data->map.count_spawn < 1)
		error_msg("Error:\nNo spawn\n", 1, data);
}

int	count_line(char *mapfile, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		error_msg("Error:\nline is invalide\n", 1, data);
	}
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	return (i);
}

void	validate_chars(t_data *data, char c)
{	
	if (c != 'C' && c != 'E' && c != 'P')
		error_msg("Error:\nCharacter invalid\n", 1, data);
	if (c == 'C')
		data->map.count_collectable += 1;
	if (c == 'E')
		data->map.count_exit += 1;
	if (c == 'P')
		data->map.count_spawn += 1;
}

void	error_msg(char *msg, int tofree, t_data *data)
{
	if (tofree == 1)
		free_tab(data->map.map_file, data->map.map_height, data, 1);
	else if (tofree == 2)
		free(data);
	write(2, msg, ft_strlen(msg));
	exit (0);
}

void	initialise_struct(t_data *data)
{
	data->map.collectable_founded = 0;
	data->map.count_collectable = 0;
	data->map.count_exit = 0;
	data->map.count_spawn = 0;
	data->map.exit_founded = 0;
	data->map.exit_x = 0;
	data->map.exit_y = 0;
	data->map.map_height = 0;
	data->map.map_widht = 0;
	data->map.spawn_x = 0;
	data->map.spawn_y = 0;
	data->win_ptr2 = 0;
	data->move = 0;
	data->stop = 1;
	data->allow = 0;
	data->allow_sprite = 0;
	data->map.enemy_x = 0;
	data->time.anim_speed2 = 0;
	data->time.anim_speed = 0;
	data->map.enemy_y = 0;
	// data->sprites.tree1
}
