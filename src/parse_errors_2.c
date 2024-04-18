/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/18 21:03:27 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_map_size(char **map)
{
	size_t	map_width;
	size_t	map_hight;

	map_width = ft_strlen(map[0]);
	map_hight = dim2_len((void **) map);
	if (map_hight > 1000 || map_width > 1000)
		return (ERR_M_SIZE);
	return (OK);
}

t_error	is_rectangle(char **map)
{
	size_t	map_width;
	size_t	len;

	map_width = ft_strlen(map[0]);
	while (*map != NULL)
	{
		len = -1;
		while ((*map)[++len] != '\0')
			;
		if (len != map_width)
			return (ERR_RECT);
		map++;
	}
	return (OK);
}
