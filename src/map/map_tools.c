/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:52:51 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:07 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **grid)
{
	size_t	i;

	i = -1;
	while (grid[++i] != NULL)
		free(grid[i]);
	free(grid);
	grid = NULL;
}

void	reset_map(char **grid)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] & MASK)
				grid[y][x] ^= MASK;
		}
	}
}

void	print_map(char **map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				ft_dprintf(2, COLOR_ERROR, map[y][x] ^ MASK);
			else if (map[y][x] == '1')
				ft_dprintf(2, COLOR_WALL, map[y][x]);
			else if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				ft_dprintf(2, COLOR_PCE, map[y][x]);
			else
				ft_dprintf(2, COLOR_GROUND, map[y][x]);
		}
		ft_dprintf(2, "\n");
	}
}

void	get_player_position(t_game_map *map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map->grid[++y] != NULL)
	{
		x = -1;
		while (map->grid[y][++x] != '\0')
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
		}
	}
}
