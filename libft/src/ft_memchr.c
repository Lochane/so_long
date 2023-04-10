/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:20:59 by lsouquie          #+#    #+#             */
/*   Updated: 2023/03/05 02:12:36 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char		*a;
	size_t					i;

	i = 0;
	a = s;
	while (i < n)
	{
		if (a[i] == (unsigned char)c)
			return ((void *)a + i);
	i++;
	}
	if ((unsigned char)c == 0 && n != 0)
		return ((void *)a + i);
	return (NULL);
}
