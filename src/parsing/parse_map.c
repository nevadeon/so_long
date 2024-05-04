/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/04 22:12:57 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_envir *env)
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
				env->player_x = x;
				env->player_y = y;
			}
		}
	}
}

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
			if (map[y][x] & MASK)
				map[y][x] ^= MASK;
		}
	}
}

/*this function takes advandate of the 8th unused bit of ascii chars to
distinguish the parts of the map that are reachable and those that aren't*/
void	parse_path(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1' || map[y][x] & MASK)
		return ;
	map[y][x] |= MASK;
	parse_path(map, x + 1, y);
	parse_path(map, x - 1, y);
	parse_path(map, x, y - 1);
	parse_path(map, x, y + 1);	
}

/*prints error mesage (in STDERR) and returns error code if map is invalid*/
t_error	parse_map(char **map, t_envir *env)
{
	if (map[0] == NULL)
		return (ft_putendl_fd(EMPTY_MAP, STDERR_FILENO), ERR_EMPTY_MAP);
	if (check_map_size(map, env))
		return (ft_putendl_fd(MAP_TOO_BIG, STDERR_FILENO), ERR_MAP_SIZE);
	if (is_rectangle(map, env))
		return (ft_putendl_fd(NOT_RECTANGLE, STDERR_FILENO), ERR_RECT);
	if (check_outer_walls(map, env))
		return (ft_putendl_fd(WRONG_MAP_WALLS, STDERR_FILENO), ERR_WALL);
	if (check_characters(map))
		return (ft_putendl_fd(UNEXPECTED_CHARACTER, STDERR_FILENO), ERR_CHAR);
	if (count_player(map))
		return (ft_putendl_fd(WRONG_PLAYER_COUNT, STDERR_FILENO), ERR_PLAYER);
	if (count_exit(map))
		return (ft_putendl_fd(WRONG_EXIT_COUNT, STDERR_FILENO), ERR_EXIT);
	if (count_collectible(map))
		return (ft_putendl_fd(WRONG_COLLECTIBLE_COUNT, STDERR_FILENO), ERR_COL);
	get_player_position(map, env);
	parse_path(map, env->player_x, env->player_y);
	if (search_unreachable(map))
		return (ft_putendl_fd(UNREACHABLE_OBJ, STDERR_FILENO), ERR_UNREACH);
	reset_map(map);
	return (OK);
}
