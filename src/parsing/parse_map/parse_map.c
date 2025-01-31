#include "so_long.h"

void	_mark_reachable_items(char **grid, uint32_t x, uint32_t y)
{
	if (grid[y][x] == '1' || grid[y][x] & 1 << 7)
		return ;
	grid[y][x] |= 1 << 7;
	_mark_reachable_items(grid, x + 1, y);
	_mark_reachable_items(grid, x - 1, y);
	_mark_reachable_items(grid, x, y - 1);
	_mark_reachable_items(grid, x, y + 1);
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
	if (count_collectible(map->grid, &map->nb_collectibles))
		return (ERR_COL);
	get_player_position(map);
	_mark_reachable_items(map->grid, map->player_index_x, map->player_index_y);
	if (check_unreachable(map->grid))
		return (ERR_UNREACH);
	reset_map(map->grid);
	return (OK);
}
