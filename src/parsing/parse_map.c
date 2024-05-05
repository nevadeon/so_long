/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/05 13:54:32 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(t_game_map *map)
{
	t_uint	y;
	t_uint	x;

	y = -1;
	while (map->grid[++y] != NULL)
	{
		x = -1;
		while (map->grid[y][++x] != '\0')
		{
			if (map->grid[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
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

/*returns an error code if map is invalid*/
t_error	parse_map(t_game_map *map)
{
	if (map->grid[0] == NULL)
		return (ERR_EMPTY_MAP);
	if (check_map_size(map))
		return (ERR_MAP_SIZE);
	if (is_rectangle(map->grid, map->width))
		return (ERR_RECT);
	if (check_outer_walls(map->grid, map->width, map->height))
		return (ERR_WALL);
	if (check_characters(map->grid))
		return (ERR_CHAR);
	if (count_player(map->grid))
		return (ERR_PLAYER);
	if (count_exit(map->grid))
		return (ERR_EXIT);
	if (count_collectible(map->grid))
		return (ERR_COL);
	get_player_position(map);
	parse_path(map->grid, map->player_x, map->player_y);
	if (search_unreachable(map->grid))
		return (ERR_UNREACH);
	reset_map(map->grid);
	return (OK);
}
