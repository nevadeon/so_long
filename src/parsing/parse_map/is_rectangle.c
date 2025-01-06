/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:35:53 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:22 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	is_rectangle(char **grid, size_t map_width)
{
	size_t	len;
	size_t	y;

	y = -1;
	while (grid[++y] != NULL)
	{
		len = -1;
		while (grid[y][++len] != '\0')
			;
		if (len != map_width)
		{
			len = -1;
			while (grid[y][++len] != '\0')
				grid[y][len] |= MASK;
			return (ERR_RECT);
		}
	}
	return (OK);
}
