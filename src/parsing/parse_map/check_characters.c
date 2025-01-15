#include "so_long.h"

t_error	check_characters(char **grid)
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
			if (grid[y][x] != 'P' && grid[y][x] != 'C' && grid[y][x] != 'E'
				&& grid[y][x] != '0' && grid[y][x] != '1')
			{
				found_error = true;
				grid[y][x] |= 1 << 7;
			}
		}
	}
	if (found_error == true)
		return (ERR_CHAR);
	reset_map(grid);
	return (OK);
}
