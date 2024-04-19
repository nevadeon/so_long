/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 17:06:22 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **map, t_position *pos)
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
				pos->error_x = x;
				pos->error_y = y;
				return (ERR_CHAR);
			}
		}
	}
	return (OK);
}

t_error	check_outer_walls(char **map, t_position *pos)
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
				pos->error_x = x;
				pos->error_y = y;
				return (ERR_WALL);
			}
		}
	}
	return (OK);
}

t_error	count_player(char **map, t_position *pos)
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
				pos->error_x = x;
				pos->error_y = y;
				nb_player += 1;
			}
		}
	}
	if (nb_player != 1)
		return (ERR_PLAYER);
	return (OK);
}

t_error	count_exit(char **map, t_position *pos)
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
				pos->error_x = x;
				pos->error_y = y;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	return (OK);
}

t_error	count_collectible(char **map, t_position *pos)
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
				pos->error_x = x;
				pos->error_y = y;
				nb_collectibles += 1;
			}
		}
	}
	if (nb_collectibles < 1)
		return (ERR_COL);
	return (OK);
}
