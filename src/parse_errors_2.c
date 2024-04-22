/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:54:34 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/22 19:00:37 by ndavenne         ###   ########.fr       */
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

t_error	check_map_size(char **map, t_environment *env)
{
	env->map_width = ft_strlen(map[0]);
	env->map_height = dim2_len((void **) map);
	if (env->map_height > 40 || env->map_width > 40)
		return (ERR_MAP_SIZE);
	return (OK);
}

t_error	is_rectangle(char **map, t_environment *env)
{
	size_t	len;
	size_t	y;

	y = -1;
	while (map[++y] != NULL)
	{
		len = -1;
		while (map[y][++len] != '\0')
			;
		if (len != env->map_width)
		{
			len = -1;
			while (map[y][++len] != '\0')
				map[y][len] |= MASK;
			return (ERR_RECT);
		}
	}
	return (OK);
}

t_error	search_unreachable(char **map)
{
	bool	found_unreach;
	size_t	x;
	size_t	y;

	found_unreach = false;
	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				map[y][x] ^= MASK;
			else if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				found_unreach = true;
				map[y][x] |= MASK;
			}
		}
	}
	if (found_unreach == true)
		return (ERR_UNREACH);
	return (OK);
}
