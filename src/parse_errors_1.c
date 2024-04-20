/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/20 14:17:38 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] != 'P' && map[y][x] != 'C' && map[y][x] != 'E'
				&& map[y][x] != '0' && map[y][x] != '1')
			{
				map[y][x] |= MASK;
				return (ERR_CHAR);
			}
		}
	}
	return (OK);
}

t_error	check_outer_walls(char **map)
{
	size_t	map_width;
	size_t	map_hight;
	size_t	x;
	size_t	y;

	map_width = ft_strlen(map[0]) - 1;
	map_hight = dim2_len((void **) map) - 1;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if ((x == 0 || x == map_width || y == 0 || y == map_hight)
				&& map[y][x] != '1')
			{
				map[y][x] |= MASK;
				return (ERR_WALL);
			}
		}
	}
	return (OK);
}

t_error	count_player(char **map)
{
	size_t	nb_player;
	size_t	x;
	size_t	y;

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

t_error	count_exit(char **map, bool apply_mask)
{
	size_t	nb_exit;
	size_t	x;
	size_t	y;

	nb_exit = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'E')
			{
				if (apply_mask == true)
					map[y][x] |= MASK;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	if (apply_mask == true)
		reset_map(map);
	return (OK);
}

t_error	count_collectible(char **map, bool apply_mask)
{
	size_t	nb_collectibles;
	size_t	x;
	size_t	y;

	nb_collectibles = 0;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'C')
			{
				if (apply_mask == true)
					map[y][x] |= MASK;
				nb_collectibles += 1;
			}
		}
	}
	if (nb_collectibles < 1)
		return (ERR_COL);
	if (apply_mask == true)
		reset_map(map);
	return (OK);
}
