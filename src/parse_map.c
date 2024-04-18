/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/18 21:16:55 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_position *pos)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\0')
		{
			if (map[j][i] == 'P')
			{
				pos->player_x = i;
				pos->player_y = j;
			}
		}
	}
}

void	parse_path(char **map, size_t x, size_t y)
{
	if (map[y][x] == '1' || map[y][x] & 128)
		return ;
	map[y][x] |= 128;
	parse_path(map, x + 1, y);
	parse_path(map, x - 1, y);
	parse_path(map, x, y - 1);
	parse_path(map, x, y + 1);
}

/*prints (in STDERR) and return an error message if map is invalid*/
t_error	parse_map(char **map, t_position *pos)
{
	if (is_rectangle(map))
		return (ft_putendl_fd(NOT_RECTANGLE, STDERR_FILENO), ERR_RECT);
	if (check_map_size(map))
		return (ft_putendl_fd(MAP_TOO_BIG, STDERR_FILENO), ERR_M_SIZE);
	if (check_characters(map))
		return (ft_putendl_fd(UNEXPECTED_CHARACTER, STDERR_FILENO), ERR_CHAR);
	if (check_outer_walls(map))
		return (ft_putendl_fd(WRONG_MAP_WALLS, STDERR_FILENO), ERR_WALL);
	if (count_player(map))
		return (ft_putendl_fd(WRONG_PLAYER_COUNT, STDERR_FILENO), ERR_PLAYER);
	if (count_exit(map))
		return (ft_putendl_fd(WRONG_EXIT_COUNT, STDERR_FILENO), ERR_EXIT);
	if (count_collectible(map))
		return (ft_putendl_fd(WRONG_COLLECTIBLE_COUNT, STDERR_FILENO), ERR_COL);
	get_player_position(map, pos);
	parse_path(map, pos->player_x, pos->player_y);
	if (!count_exit(map))
		return (ft_putendl_fd(UNREACHABLE_EXIT, STDERR_FILENO), PATH_E);
	if (!count_collectible(map))
		return (ft_putendl_fd(UNREACHABLE_COLLECTIBLE, STDERR_FILENO), PATH_C);
	return (OK);
}
