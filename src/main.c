/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/22 13:00:36 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(t_game_map *map, t_game_visuals *gv)
{
	(void)map;
	init_graphics(gv);
	display_menu(gv);
	mlx_key_hook(gv->mlx, update_menu, gv);
	mlx_loop_hook(gv->mlx, update_graphics, gv);
	mlx_loop(gv->mlx);
}

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_visuals	gv;

	parse_inputs(argc, argv, &map);
	so_long(&map, &gv);
	// free_graphics(&gv);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
