/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:43:57 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/25 15:29:09 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_accessibility(t_data *data)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	data->map.collectable_founded = 0;
	data->map.exit_founded = 0;
	tab = malloc(sizeof(char *) * (data->map.map_height + 1));
	if (!tab)
		exit (0);
	tab = copy_tab(tab, data->map.map_file, data);
	found_spawn(tab, data);
	found_path(data, tab, data->map.spawn_x, data->map.spawn_y);
	if ((data->map.collectable_founded != data->map.count_collectable)
		|| (data->map.exit_founded != 1))
	{
		error_msg("Error: Map can't be won\n", 1, data);
	}
	free_tab(tab, data->map.map_height, data, 0);
}

void	found_path(t_data *data, char **tab, int x, int y)
{
	if (x <= 0 || x >= data->map.map_height
		|| y <= 0 || y >= data->map.map_widht)
		return ;
	if (tab[x][y] != 'C' && tab[x][y] != '0'
		&& tab[x][y] != 'E' && tab[x][y] != 'P')
		return ;
	if (tab[x][y] == 'C')
		data->map.collectable_founded += 1;
	if (tab[x][y] == 'E')
		data->map.exit_founded = 1;
	tab[x][y] = '2';
	found_path(data, tab, x, y + 1);
	found_path(data, tab, x, y - 1);
	found_path(data, tab, x + 1, y);
	found_path(data, tab, x - 1, y);
}

int	found_spawn(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != 'P' && tab[i][j] != 'E')
			j++;
		if (tab[i][j] == 'P')
		{
			data->map.spawn_x = j;
			data->map.spawn_y = i;
		}
		if (tab[i][j] == 'E')
		{
			data->map.exit_x = j;
			data->map.exit_y = i;
		}
		i++;
	}
	return (0);
}
