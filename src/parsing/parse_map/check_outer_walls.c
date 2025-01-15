#include "so_long.h"

t_error	check_outer_walls(char **grid, size_t map_width, size_t map_height)
{
	bool	found_error;
	size_t	x;
	size_t	y;

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
				grid[y][x] |= 1 << 7;
			}
		}
	}
	if (found_error == true)
		return (ERR_WALL);
	reset_map(grid);
	return (OK);
}
