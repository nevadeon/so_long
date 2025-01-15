#include "so_long.h"

t_error	is_rectangle(char **grid, size_t map_width)
{
	size_t	len;
	size_t	y;

	y = -1;
	while (grid[++y] != NULL)
	{
		len = -1;
		while (grid[y][++len] != '\0')
			;
		if (len != map_width)
		{
			len = -1;
			while (grid[y][++len] != '\0')
				grid[y][len] |= 1 << 7;
			return (ERR_RECT);
		}
	}
	return (OK);
}
