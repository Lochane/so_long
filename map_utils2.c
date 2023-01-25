/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:11:51 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/20 17:25:57 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count(const char *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] != '\n')
		i++;
	return (i);
}

char	**copy_tab(char **dest, char **src, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.map_height)
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	return (dest);
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