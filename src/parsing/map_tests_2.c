/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/04 01:00:29 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_map_size(t_game_map *map)
{
	map->width = ft_strlen(map->grid[0]);
	map->height = dim2_len((void **) map->grid);
	if (map->height > 40 || map->width > 40)
		return (ERR_MAP_SIZE);
	return (OK);
}

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

t_error	check_unreachable(char **grid)
{
	bool	found_unreach;
	size_t	x;
	size_t	y;

	found_unreach = false;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] & MASK)
				grid[y][x] ^= MASK;
			else if (grid[y][x] == 'E' || grid[y][x] == 'C')
			{
				found_unreach = true;
				grid[y][x] |= MASK;
			}
		}
	}
	if (found_unreach == true)
		return (ERR_UNREACH);
	return (OK);
}
