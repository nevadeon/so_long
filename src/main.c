/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/20 17:09:56 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_position *pos)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				pos->player_x = x;
				pos->player_y = y;
			}
		}
	}
}

t_position	*pos_init(char **map)
{
	t_position	*pos;

	pos = (t_position *) malloc(sizeof(t_position));
	get_player_position(map, pos);
	return (pos);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_position	*pos;

	if (verif_arg(argc, argv[1]))
		return (1);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map(DEFAULT_MAP_PATH);
	if (map == NULL)
		return (ft_putendl_fd(FAILED_TO_OPEN, STDERR_FILENO), ERR_OPEN);
	pos = pos_init(map);
	if (parse_map(map, pos) != OK)
	{
		print_map(map);
		return (free_map(map), free(pos), 1);
	}
	return (free_map(map), free(pos), 0);
}
