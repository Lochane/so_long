/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:15:37 by lsouquie          #+#    #+#             */
/*   Updated: 2023/01/24 14:02:26 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	validate_map(argc, argv[1], data);
	parsing_map(argv[1], data);
	so_long(data);
	free(data);
	return (0);
}
