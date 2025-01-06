/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_reachable_items.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:33:38 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:23 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mark_reachable_items(char **grid, size_t x, size_t y)
{
	if (grid[y][x] == '1' || grid[y][x] & MASK)
		return ;
	grid[y][x] |= MASK;
	mark_reachable_items(grid, x + 1, y);
	mark_reachable_items(grid, x - 1, y);
	mark_reachable_items(grid, x, y - 1);
	mark_reachable_items(grid, x, y + 1);
}