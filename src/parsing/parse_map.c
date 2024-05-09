/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/10 00:20:22 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_reachable_items(char **map, uint32_t x, uint32_t y)
{
	if (map[y][x] == '1' || map[y][x] & MASK)
		return ;
	map[y][x] |= MASK;
	mark_reachable_items(map, x + 1, y);
	mark_reachable_items(map, x - 1, y);
	mark_reachable_items(map, x, y - 1);
	mark_reachable_items(map, x, y + 1);
}

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
	mark_reachable_items(map->grid, map->player_x, map->player_y);
	if (check_unreachable(map->grid))
		return (ERR_UNREACH);
	reset_map(map->grid);
	return (OK);
}
