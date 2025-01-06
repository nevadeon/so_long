/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:02:44 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_visuals	gv;

	parse_args(argc, argv, &map);
	init_graphics(&gv);
	display_menu(&gv);
	mlx_key_hook(gv.mlx, update_menu, &gv);
	mlx_loop_hook(gv.mlx, update_graphics, &gv);
	mlx_loop(gv.mlx);
	// free_graphics(&gv);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
