/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:47:55 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 17:22:39 by ndavenne         ###   ########.fr       */
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

void	print_map(char **map, t_position *pos)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		if (y == pos->error_y)
		{
			x = -1;
			while (map[y][++x] != '\0')
			{
				if (x == pos->error_x)
					ft_printf("\033[38;2;255;0;5;5m%c\033[0m", map[y][x]);
				else
					ft_printf("%c", map[y][x]);
			}
		}
		else
			ft_printf("%s", map[y]);
		ft_printf("\n");
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
