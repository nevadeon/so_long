/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/14 17:03:30 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **grid)
{
	bool		found_error;
	uint32_t	x;
	uint32_t	y;

	found_error = false;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] != 'P' && grid[y][x] != 'C' && grid[y][x] != 'E'
				&& grid[y][x] != '0' && grid[y][x] != '1')
			{
				found_error = true;
				grid[y][x] |= MASK;
			}
		}
	}
	if (found_error == true)
		return (ERR_CHAR);
	reset_map(grid);
	return (OK);
}

t_error	check_outer_walls(char **grid, size_t map_width, size_t map_height)
{
	bool		found_error;
	uint32_t	x;
	uint32_t	y;

	found_error = false;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if ((x == 0 || x == map_width - 1 || y == 0
					|| y == map_height - 1) && grid[y][x] != '1')
			{
				found_error = true;
				grid[y][x] |= MASK;
			}
		}
	}
	if (found_error == true)
		return (ERR_WALL);
	reset_map(grid);
	return (OK);
}

t_error	count_player(char **grid)
{
	uint32_t	nb_player;
	uint32_t	x;
	uint32_t	y;

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

t_error	count_exit(char **grid)
{
	uint32_t	nb_exit;
	uint32_t	x;
	uint32_t	y;

	nb_exit = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'E')
			{
				grid[y][x] |= MASK;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	reset_map(grid);
	return (OK);
}

t_error	count_collectible(char **grid)
{
	uint32_t	nb_collectibles;
	uint32_t	x;
	uint32_t	y;

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
