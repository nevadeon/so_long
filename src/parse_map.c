/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 18:35:19 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_position *pos)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				pos->player_x = x;
				pos->player_y = y;
			}
		}
	}
}

void	mark_unreachable(char **map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & 128)
				map[y][x] ^= 128;
			else if (map[y][x] == 'E' || map[y][x] == 'C')
				map[y][x] |= 128;
		}
	}
}

/*undo changes done by parse_path*/
void	reset_map(char **map)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & 128)
				map[y][x] ^= 128;
		}
	}
}

/*this function takes advandate of the 8th unused bit of ascii chars to
distinguish the parts of the map that are reachable and those that aren't*/
void	parse_path(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1' || map[y][x] & 128)
		return ;
	map[y][x] |= 128;
	parse_path(map, x + 1, y);
	parse_path(map, x - 1, y);
	parse_path(map, x, y - 1);
	parse_path(map, x, y + 1);
}

/*prints error mesage (in STDERR) and returns error code if map is invalid*/
t_error	parse_map(char **map, t_position *pos)
{
	if (map[0] == NULL)
		return (ft_putendl_fd(EMPTY_MAP, STDERR_FILENO), ERR_EMPTY);
	if (is_rectangle(map, pos))
		return (ft_putendl_fd(NOT_RECTANGLE, STDERR_FILENO), ERR_RECT);
	if (check_map_size(map))
		return (ft_putendl_fd(MAP_TOO_BIG, STDERR_FILENO), ERR_MAP_SIZE);
	if (check_characters(map, pos))
		return (ft_putendl_fd(UNEXPECTED_CHARACTER, STDERR_FILENO), ERR_CHAR);
	if (check_outer_walls(map, pos))
		return (ft_putendl_fd(WRONG_MAP_WALLS, STDERR_FILENO), ERR_WALL);
	if (count_player(map, pos))
		return (ft_putendl_fd(WRONG_PLAYER_COUNT, STDERR_FILENO), ERR_PLAYER);
	if (count_exit(map, pos))
		return (ft_putendl_fd(WRONG_EXIT_COUNT, STDERR_FILENO), ERR_EXIT);
	if (count_collectible(map, pos))
		return (ft_putendl_fd(WRONG_COLLECTIBLE_COUNT, STDERR_FILENO), ERR_COL);
	get_player_position(map, pos);
	parse_path(map, pos->player_x, pos->player_y);
	if (!count_exit(map, pos) || !count_collectible(map, pos))
	{
		mark_unreachable(map);
		return (ft_putendl_fd(UNREACHABLE_OBJ, STDERR_FILENO), ERR_UNREACH);
	}
	reset_map(map);
	return (OK);
}
