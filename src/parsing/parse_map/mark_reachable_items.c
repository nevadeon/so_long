#include "so_long.h"

void	mark_reachable_items(char **grid, size_t x, size_t y)
{
	if (grid[y][x] == '1' || grid[y][x] & 1 << 7)
		return ;
	grid[y][x] |= 1 << 7;
	mark_reachable_items(grid, x + 1, y);
	mark_reachable_items(grid, x - 1, y);
	mark_reachable_items(grid, x, y - 1);
	mark_reachable_items(grid, x, y + 1);
}
