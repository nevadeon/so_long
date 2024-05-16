/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:51:09 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/16 16:45:38 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_select_anim(t_game_visuals *graphs)
{
	t_sprite	select_sprite;

	select_sprite = (t_sprite){
		.file_path = SELECT_SPRITE,
		.nb_frames = 3,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0
	};
	load_animation(graphs->mlx, &graphs->select_anim, &select_sprite);
}

void	init_menu_bg_anim(t_game_visuals *graphs)
{
	t_sprite	menu_bg_sprite;

	menu_bg_sprite = (t_sprite){
		.file_path = MENU_SPRITE,
		.nb_frames = 24,
		.frame_width = 1309,
		.frame_height = 995,
		.padding_x = 10,
		.padding_y = 10
	};
	graphs->menu_bg_anim = (t_animation){
		.refresh_time = 100,
		.time_counter = 0
	};
	load_animation(graphs->mlx, &graphs->menu_bg_anim, &menu_bg_sprite);
}

void	init_graphics(t_game_visuals *graphs)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*graphs = (t_game_visuals){
		.mlx = mlx,
		.background = new_image(mlx, WIDTH, HEIGHT),
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
	init_menu_bg_anim(graphs);
	init_select_anim(graphs);
}
