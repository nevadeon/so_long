/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:38:31 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 10:38:50 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	count_exit(char **grid)
{
	size_t	nb_exit;
	size_t	x;
	size_t	y;

	nb_exit = 0;
	y = -1;
	while (grid[++y] != NULL)
	{
		x = -1;
		while (grid[y][++x] != '\0')
		{
			if (grid[y][x] == 'E')
			{
				grid[y][x] |= MASK;
				nb_exit += 1;
			}
		}
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	reset_map(grid);
	return (OK);
}
