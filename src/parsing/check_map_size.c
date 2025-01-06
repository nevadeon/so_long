/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:37:28 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 10:37:36 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_map_size(t_game_map *map)
{
	map->width = ft_strlen(map->grid[0]);
	map->height = dim2_len((void **) map->grid);
	if (map->height > 40 || map->width > 40)
		return (ERR_MAP_SIZE);
	return (OK);
}
