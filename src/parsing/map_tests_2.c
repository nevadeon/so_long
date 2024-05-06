/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 16:35:28 by ndavenne         ###   ########.fr       */
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

t_error	is_rectangle(char **map, size_t map_width)
{
	size_t		len;
	uint32_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		len = -1;
		while (map[y][++len] != '\0')
			;
		if (len != map_width)
		{
			len = -1;
			while (map[y][++len] != '\0')
				map[y][len] |= MASK;
			return (ERR_RECT);
		}
	}
	return (OK);
}

t_error	search_unreachable(char **map)
{
	bool		found_unreach;
	uint32_t	x;
	uint32_t	y;

	found_unreach = false;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				map[y][x] ^= MASK;
			else if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				found_unreach = true;
				map[y][x] |= MASK;
			}
		}
	}
	if (found_unreach == true)
		return (ERR_UNREACH);
	return (OK);
}
