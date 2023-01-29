/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:43:57 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/28 23:52:43 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	check_accessibility(t_data *data)
{
	char	**tab;
	char	bool;

	bool = 1;
	data->map.collectable_founded = 0;
	data->map.exit_founded = 0;
	tab = malloc(sizeof(char *) * (data->map.map_height + 1));
	if (!tab)
		exit (0);
	copy_tab(tab, data->map.map_file, data);
	found_spawn(tab, data);
	found_exit(tab, data);
	while (bool)
		bool = found_path(data, tab);
	if ((data->map.collectable_founded != data->map.count_collectable)
		|| (data->map.exit_founded != 1))
		error_msg("Error:\nMap can't be won\n", 1, data);
	free_tab(tab, data->map.map_height, data, 0);
}

char	found_path(t_data *data, char **tab)
{
	int		i;
	int		j;
	char	bool;

	i = 0;
	j = 0;
	bool = 0;
	print(tab);
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P' || tab[i][j] == '2')
			{
				bool += fill_path(data, tab, i, j);
				//print(tab)
			}
			j++;
		}
		i++;
	}
	return (bool);
}

char	fill_path(t_data *data, char **tab, int i, int j)
{
	char	a;

	a = 0;
	a += overflow(data, tab, i + 1, j);
	a += overflow(data, tab, i - 1, j);
	a += overflow(data, tab, i, j + 1);
	a += overflow(data, tab, i, j - 1);
	return (a);
}

char	overflow(t_data *data, char **tab, int i, int j)
{
	if (tab[i][j] == 'C')
		data->map.collectable_founded += 1;
	if (tab[i][j] == 'E')
		data->map.exit_founded = 1;
	if (tab[i][j] == '0' || tab[i][j] == 'E' || tab[i][j] == 'C')
	{
		tab[i][j] = '2';
		return (1);
	}
	return (0);
}

void	ft_print_double_tab(char **tab)
{
	int i = 0;

	while(tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	printf("\n\n");
}
