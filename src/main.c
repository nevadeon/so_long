/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/07 13:58:40 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	so_long(t_game_map *map, t_game_visuals *graphs)
// {
// 	init_graphics(graphs);
// 	display_menu(graphs);
// 	mlx_loop(graphs->mlx);
// }

int	main(int argc, char *argv[])
{
	t_game_map		map;
	// t_game_visuals	graphs;

	parse_inputs(argc, argv, &map);
	// so_long(&map, &graphs);
	// free_grahics(graphs);
	// free_map(map.grid);
	return (EXIT_SUCCESS);
}
