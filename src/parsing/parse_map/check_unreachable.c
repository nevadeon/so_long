/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unreachable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:36:44 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:18 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_unreachable(char **grid)
{
	bool	found_unreach;
	size_t	x;
	size_t	y;

	found_unreach = false;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] & MASK)
				grid[y][x] ^= MASK;
			else if (grid[y][x] == 'E' || grid[y][x] == 'C')
			{
				found_unreach = true;
				grid[y][x] |= MASK;
			}
		}
	}
	if (found_unreach == true)
		return (ERR_UNREACH);
	return (OK);
}
