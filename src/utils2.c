/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:11:51 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/28 17:25:17 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

int	count(const char *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	return (i);
}

void	copy_tab(char **dest, char **src, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.map_height)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
}

void	*free_tab(char **res, size_t i, t_data *data, int allowfree)
{
	while (i-- > 0)
		free(res[i]);
	free(res);
	if (allowfree == 1)
		free(data);
	return (NULL);
}

int	found_spawn(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.map_height)
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != 'P')
			j++;
		if (tab[i][j] == 'P')
		{
			data->map.spawn_x = j;
			data->map.spawn_y = i;
			break ;
		}
		i++;
	}
	return (0);
}

int	found_exit(char **tab, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.map_height)
	{
		j = 0;
		while (tab[i][j] && tab[i][j] != 'E')
			j++;
		if (tab[i][j] == 'E')
		{
			data->map.exit_x = j;
			data->map.exit_y = i;
			break ;
		}
		i++;
	}
	return (0);
}
