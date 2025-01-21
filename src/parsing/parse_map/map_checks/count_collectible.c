#include "so_long.h"

t_error	count_collectible(char **grid, uint32_t *nb_collectibles)
{
	uint32_t	x;
	uint32_t	y;

	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'C')
			{
				grid[y][x] |= 1 << 7;
				*nb_collectibles = *nb_collectibles + 1;
			}
		}
	}
	if (*nb_collectibles < 1)
		return (ERR_COL);
	reset_map(grid);
	return (OK);
}
