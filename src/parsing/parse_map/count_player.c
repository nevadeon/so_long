#include "so_long.h"

t_error	count_player(char **grid)
{
	size_t	nb_player;
	size_t	x;
	size_t	y;

	nb_player = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'P')
			{
				grid[y][x] |= MASK;
				nb_player += 1;
			}
		}
	}
	if (nb_player != 1)
		return (ERR_PLAYER);
	reset_map(grid);
	return (OK);
}
