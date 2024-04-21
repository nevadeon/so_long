/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/22 00:34:03 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **map)
{
	bool	found_error;
	size_t	x;
	size_t	y;

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

t_error	check_outer_walls(char **map, t_environment *env)
{
	bool	found_error;
	size_t	x;
	size_t	y;

	found_error = false;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if ((x == 0 || x == env->map_width - 1 || y == 0
					|| y == env->map_hight - 1) && map[y][x] != '1')
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
