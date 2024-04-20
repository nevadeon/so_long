/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/20 20:39:04 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	verif_arg(int argc, char *filename)
{
	size_t	len;

	if (argc > 2)
		return (ft_putendl_fd(TOO_MANY_ARGS, STDERR_FILENO), ERR_ARGS);
	if (argc == 2)
	{
		len = ft_strlen(filename);
		if (len < 5)
			return (ft_putendl_fd(SHORT_FILE_NAME, STDERR_FILENO), ERR_NAME);
		if (memcmp(filename + len - 4, ".ber", 4))
			return (ft_putendl_fd(WRONG_FILE_EXT, STDERR_FILENO), ERR_EXT);
	}
	return (OK);
}

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

t_error	is_rectangle(char **map)
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
			len = -1;
			while (map[y][++len] != '\0')
				map[y][len] |= MASK;
			return (ERR_RECT);
		}
	}
	return (OK);
}
