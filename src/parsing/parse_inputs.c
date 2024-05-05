/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:13:15 by nevadeon          #+#    #+#             */
/*   Updated: 2024/05/05 14:34:28 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(t_error error_code)
{
	ft_putendl_fd(get_error_message(error_code), STDERR_FILENO);
	exit(error_code);
}

void	parse_arg(int argc, char *filename)
{
	size_t	len;

	if (argc > 2)
		error(ERR_ARGS);
	if (argc == 2)
	{
		len = ft_strlen(filename);
		if (len < 5)
			error(ERR_NAME);
		if (memcmp(filename + len - 4, ".ber", 4))
			error(ERR_EXT);
	}
}

void	parse_inputs(int argc, char *argv[], t_game_map *map)
{
	t_error	error_code;

	parse_arg(argc, argv[1]);
	if (argc > 1)
		map->grid = get_map(argv[1]);
	else
		map->grid = get_map(DEFAULT_MAP_PATH);
	if (map->grid == NULL)
		error(ERR_OPEN);
	error_code = parse_map(map);
	if (error_code != OK)
	{
		if (error_code != ERR_MAP_SIZE)
			print_map(map->grid);
		free_map(map->grid);
		error(error_code);
	}
}
