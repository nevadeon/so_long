/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:59:47 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/18 20:54:08 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_error	check_characters(char **map)
{
	size_t	i;

	while (*map != NULL)
	{
		i = -1;
		while ((*map)[++i] != '\0')
			if ((*map)[i] != 'P' && (*map)[i] != 'C' && (*map)[i] != 'E'
				&& (*map)[i] != '0' && (*map)[i] != '1')
				return (ERR_CHAR);
		map++;
	}
	return (OK);
}

t_error	check_outer_walls(char **map)
{
	size_t	map_width;
	size_t	map_hight;
	size_t	i;
	size_t	j;

	map_width = ft_strlen(map[0]) - 1;
	map_hight = dim2_len((void **) map) - 1;
	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
			if ((i == 0 || i == map_hight || j == 0 || j == map_width)
				&& map[i][j] != '1')
				return (ERR_WALL);
	}
	return (OK);
}

t_error	count_player(char **map)
{
	size_t	nb_player;
	size_t	i;

	nb_player = 0;
	while (*map != NULL)
	{
		i = -1;
		while ((*map)[++i] != '\0')
			nb_player += ((*map)[i] == 'P');
		map++;
	}
	if (nb_player != 1)
		return (ERR_PLAYER);
	return (OK);
}

t_error	count_exit(char **map)
{
	size_t	nb_exit;
	size_t	i;

	nb_exit = 0;
	while (*map != NULL)
	{
		i = -1;
		while ((*map)[++i] != '\0')
			nb_exit += ((*map)[i] == 'E');
		map++;
	}
	if (nb_exit != 1)
		return (ERR_EXIT);
	return (OK);
}

t_error	count_collectible(char **map)
{
	size_t	nb_collectibles;
	size_t	i;

	nb_collectibles = 0;
	while (*map != NULL)
	{
		i = -1;
		while ((*map)[++i] != '\0')
			nb_collectibles += ((*map)[i] == 'C');
		map++;
	}
	if (nb_collectibles < 1)
		return (ERR_COL);
	return (OK);
}
