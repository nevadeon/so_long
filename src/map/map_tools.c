/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:52:51 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 20:06:46 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

void	reset_map(char **map)
{
	uint32_t	x;
	uint32_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				map[y][x] ^= MASK;
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
				ft_printf(2, COLOR_ERROR, map[y][x] ^ MASK);
			else if (map[y][x] == '1')
				ft_printf(2, COLOR_WALL, map[y][x]);
			else if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				ft_printf(2, COLOR_PCE, map[y][x]);
			else
				ft_printf(2, COLOR_GROUND, map[y][x]);
		}
		ft_printf(2, "\n");
	}
}

void	get_player_position(t_game_map *map)
{
	uint32_t	y;
	uint32_t	x;

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
