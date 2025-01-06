#include "so_long.h"

t_error	check_map_size(t_game_map *map)
{
	map->width = ft_strlen(map->grid[0]);
	map->height = dim2_len((void **) map->grid);
	if (map->height > 40 || map->width > 40)
		return (ERR_MAP_SIZE);
	return (OK);
}
