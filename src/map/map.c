/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:47:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/05 00:09:36 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	size_t	i;

	i = -1;
	while (map[++i] != NULL)
		free(map[i]);
	free(map);
}

void	print_map(char **map)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				ft_printf(2, COLOR_UNREACH, map[y][x] ^ MASK);
			else if (map[y][x] == '1')
				ft_printf(2, COLOR_WALL, map[y][x]);
			else if (map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				ft_printf(2, COLOR_PCE, map[y][x]);
			else
				ft_printf(2, COLOR_GROUND, map[y][x]);
		}
		ft_printf(2, "\n");
	}
}

/*copy an array of strings in a new mallocated array
then add a string at the end and free the old array*/
char	**_dim2join_free(char **tab, char *str)
{
	char	**output;
	size_t	len;

	len = dim2_len((void **) tab) + 1;
	output = (char **) malloc(sizeof(char *) * (len + 1));
	dim2_cpy((void **) output, (void **) tab);
	output[len - 1] = str;
	output[len] = NULL;
	free(tab);
	return (output);
}

/*puts each line of a text file in an array of strings*/
char	**get_map(char *file_name)
{
	char	**map;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char **) malloc(sizeof(char *));
	map[0] = NULL;
	line = get_next_line(fd);
	while (line)
	{
		line[ft_strclen2(line, '\n')] = '\0';
		map = _dim2join_free(map, line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}
