#include "so_long.h"

t_error	count_exit(char **grid)
{
	uint32_t	nb_exit;
	uint32_t	x;
	uint32_t	y;

	nb_exit = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'E')
			{
				grid[y][x] |= 1 << 7;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	reset_map(grid);
	return (OK);
}
