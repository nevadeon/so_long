/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:51:09 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/20 22:25:14 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_select_anim(t_game_visuals *gv)
{
	t_sprite	select_sprite;

	select_sprite = (t_sprite){
		.file_path = SELECT_SPRITE,
		.nb_frames = 4,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0
	};
	gv->select_anim = (t_animation){
		.render_layer = new_image(gv->mlx, WIDTH, HEIGHT),
		.refresh_time = 200,
		.time_counter = 0
	};
	load_animation(gv->mlx, &gv->select_anim, &select_sprite);
}

void	init_menu_bg_anim(t_game_visuals *gv)
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
	gv->menu_bg_anim = (t_animation){
		.render_layer = new_image(gv->mlx, WIDTH, HEIGHT),
		.refresh_time = 100,
		.time_counter = 0
	};
	load_animation(gv->mlx, &gv->menu_bg_anim, &menu_bg_sprite);
}

void	init_graphics(t_game_visuals *gv)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*gv = (t_game_visuals){
		.mlx = mlx,
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON),
		.game_status = IN_MENU,
		.selected_button = BTN_START
	};
	init_menu_bg_anim(gv);
	init_select_anim(gv);
}
