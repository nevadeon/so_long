/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 19:15:28 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_map_size(char **map)
{
	size_t	map_width;
	size_t	map_hight;

	map_width = ft_strlen(map[0]);
	map_hight = dim2_len((void **) map);
	if (map_hight > 1000 || map_width > 80)
		return (ERR_MAP_SIZE);
	return (OK);
}

t_error	is_rectangle(char **map, t_position *pos)
{
	size_t	map_width;
	size_t	len;
	size_t	y;

	map_width = ft_strlen(map[0]);
	y = -1;
	while (map[++y] != NULL)
	{
		len = -1;
		while (map[y][++len] != '\0')
			;
		if (len != map_width)
		{
			pos->error_x = len;
			pos->error_y = y;
			return (ERR_RECT);
		}
	}
	return (OK);
}
