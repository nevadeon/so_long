#include "so_long.h"

t_error	check_outer_walls(char **grid, uint32_t width, uint32_t height)
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
			if ((x == 0 || x == width - 1 || y == 0 || y == height - 1)
				&& grid[y][x] != '1')
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
