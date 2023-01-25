/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:10:42 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/20 16:02:26 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_char(t_data *data)
{
	if (data->map.count_collectable == 0)
		error_msg("Error: Too few collectable\n", 1, data);
	if (data->map.count_exit > 1)
		error_msg("Error: Too many exit\n", 1, data);
	if (data->map.count_exit < 1)
		error_msg("Error: No exit\n", 1, data);
	if (data->map.count_spawn > 1)
		error_msg("Error: Too many spawn\n", 1, data);
	if (data->map.count_spawn < 1)
		error_msg("Error: No spawn\n", 1, data);
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
		error_msg("Error: line is invalide\n", 1, data);
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
		error_msg("Error: Character invalid\n", 1, data);
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
	write(2, msg, ft_strlen(msg));
	exit (0);
}
