#include "so_long.h"

t_error	is_rectangle(char **grid, uint32_t map_width)
{
	uint32_t	len;
	uint32_t	y;

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
