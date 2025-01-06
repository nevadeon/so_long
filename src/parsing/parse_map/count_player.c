/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:39:13 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:21 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	count_player(char **grid)
{
	size_t	nb_player;
	size_t	x;
	size_t	y;

	nb_player = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'P')
			{
				grid[y][x] |= MASK;
				nb_player += 1;
			}
		}
	}
	if (nb_player != 1)
		return (ERR_PLAYER);
	reset_map(grid);
	return (OK);
}
