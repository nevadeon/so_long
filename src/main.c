/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 18:55:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game_map *map, t_game_visuals *graph)
{
	init_graphics(graph);
	display_menu(graph);
	mlx_loop(graph->mlx);
}

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_visuals	graph;

	parse_inputs(argc, argv, &map);
	so_long(&map, &graph);
	free_grahics(graph);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
