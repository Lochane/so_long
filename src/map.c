/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:59 by lsouquie          #+#    #+#             */
/*   Updated: 2023/02/27 13:14:36 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	validate_map(int argc, char *mapfile, t_data *data)
{
	int	fd;

	if (argc > 2)
		error_msg("Error:\nToo many arguments", 2, data);
	if (ft_strncmp(".ber", &mapfile[ft_strlen(mapfile) - 4],
			ft_strlen(mapfile)) != 0)
		error_msg("Error:\nfile is not .ber\n", 2, data);
	fd = open(mapfile, __O_DIRECTORY);
	if (fd > 0)
	{
		close (fd);
		error_msg("Error:\nfd superieur a 0\n", 2, data);
	}
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_msg("Error:\nfd inferieur a 0\n", 2, data);
	}
	close (fd);
}

void	parsing_map(char *mapfile, t_data *data)
{
	map_to_tab(mapfile, data);
	check_mapsize(data);
	check_mapintegrity(data);
}

void	check_mapsize(t_data *data)
{
	int	i;

	i = 0;
	data->map.map_widht = count(data->map.map_file[i]);
	while (i < data->map.map_height)
	{
		if ((int)count(data->map.map_file[i]) != data->map.map_widht)
			error_msg("Error:\nline is not the same size\n", 1, data);
		i++;
	}
}

void	check_mapintegrity(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map.map_widht)
	{
		i = 0;
		while (i < data->map.map_height)
		{
			if (i == 0 || j == 0 || i == data->map.map_height - 1
				|| j == data->map.map_widht - 1)
			{
				if (data->map.map_file[i][j] != '1')
					error_msg("Error:\nMap not surrounded by walls\n", 1, data);
			}
			else if (data->map.map_file[i][j] != '1'
						&& data->map.map_file[i][j] != '0')
				validate_chars(data, data->map.map_file[i][j]);
			i++;
		}
	j++;
	}
	error_char(data);
	check_accessibility(data);
}

void	map_to_tab(char *mapfile, t_data *data)
{
	int		fd;
	int		i;
	char	*line;
	char	**mapdata;

	i = 0;
	fd = open(mapfile, O_RDONLY);
	data->map.map_height = count_line(mapfile, data);
	mapdata = malloc(sizeof(char *) * (data->map.map_height + 1));
	if (!mapdata)
		return ;
	line = get_next_line(fd);
	if (!line)
		return ;
	while (line)
	{
		mapdata[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	data->map.map_file = malloc(sizeof(char *) * (data->map.map_height + 1));
	copy_tab(data->map.map_file, mapdata, data);
	free_tab(mapdata, i, data, 0);
}
