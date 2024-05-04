/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/05 00:02:05 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_game_data *env)
{
	t_uint	y;
	t_uint	x;

	y = -1;
	while (env->map[++y] != NULL)
	{
		x = -1;
		while (env->map[y][++x] != '\0')
		{
			if (env->map[y][x] == 'P')
			{
				env->player_x = x;
				env->player_y = y;
			}
		}
	}
}

void	reset_map(char **map)
{
	t_uint	x;
	t_uint	y;

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
void	parse_path(char **map, t_uint x, t_uint y)
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
t_error	parse_map(t_game_data *env)
{
	if (env->map[0] == NULL)
		return (ft_putendl_fd(EMPTY_MAP, STDERR_FILENO), ERR_EMPTY_MAP);
	if (check_map_size(env))
		return (ft_putendl_fd(MAP_TOO_BIG, STDERR_FILENO), ERR_MAP_SIZE);
	if (is_rectangle(env->map, env->map_width))
		return (ft_putendl_fd(NOT_RECTANGLE, STDERR_FILENO), ERR_RECT);
	if (check_outer_walls(env->map, env->map_width, env->map_height))
		return (ft_putendl_fd(WRONG_MAP_WALLS, STDERR_FILENO), ERR_WALL);
	if (check_characters(env->map))
		return (ft_putendl_fd(UNEXPECTED_CHARACTER, STDERR_FILENO), ERR_CHAR);
	if (count_player(env->map))
		return (ft_putendl_fd(WRONG_PLAYER_COUNT, STDERR_FILENO), ERR_PLAYER);
	if (count_exit(env->map))
		return (ft_putendl_fd(WRONG_EXIT_COUNT, STDERR_FILENO), ERR_EXIT);
	if (count_collectible(env->map))
		return (ft_putendl_fd(WRONG_COLLECTIBLE_COUNT, STDERR_FILENO), ERR_COL);
	get_player_position(env);
	parse_path(env->map, env->player_x, env->player_y);
	if (search_unreachable(env->map))
		return (ft_putendl_fd(UNREACHABLE_OBJ, STDERR_FILENO), ERR_UNREACH);
	reset_map(env->map);
	return (OK);
}
