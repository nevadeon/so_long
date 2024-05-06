/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 22:55:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **map)
{
	bool		found_error;
	uint32_t	x;
	uint32_t	y;

	found_error = false;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E'
				&& map[y][x] != '0' && map[y][x] != '1')
			{
				found_error = true;
				map[y][x] |= MASK;
			}
		}
	}
	if (found_error == true)
		return (ERR_CHAR);
	reset_map(map);
	return (OK);
}

t_error	check_outer_walls(char **map, size_t map_width, size_t map_height)
{
	bool		found_error;
	uint32_t	x;
	uint32_t	y;

	found_error = false;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if ((x == 0 || x == map_width - 1 || y == 0
					|| y == map_height - 1) && map[y][x] != '1')
			{
				found_error = true;
				map[y][x] |= MASK;
			}
		}
	}
	if (found_error == true)
		return (ERR_WALL);
	reset_map(map);
	return (OK);
}

t_error	count_player(char **map)
{
	uint32_t	nb_player;
	uint32_t	x;
	uint32_t	y;

	nb_player = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				map[y][x] |= MASK;
				nb_player += 1;
			}
		}
	}
	if (nb_player != 1)
		return (ERR_PLAYER);
	reset_map(map);
	return (OK);
}

t_error	count_exit(char **map)
{
	uint32_t	nb_exit;
	uint32_t	x;
	uint32_t	y;

	nb_exit = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'E')
			{
				map[y][x] |= MASK;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	reset_map(map);
	return (OK);
}

t_error	count_collectible(char **map)
{
	uint32_t	nb_collectibles;
	uint32_t	x;
	uint32_t	y;

	nb_collectibles = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'C')
			{
				map[y][x] |= MASK;
				nb_collectibles += 1;
			}
		}
	}
	if (nb_collectibles < 1)
		return (ERR_COL);
	reset_map(map);
	return (OK);
}
