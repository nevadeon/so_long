/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:38:00 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:20 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	count_collectible(char **grid)
{
	size_t	nb_collectibles;
	size_t	x;
	size_t	y;

	nb_collectibles = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'C')
			{
				grid[y][x] |= MASK;
				nb_collectibles += 1;
			}
		}
	}
	if (nb_collectibles < 1)
		return (ERR_COL);
	reset_map(grid);
	return (OK);
}
