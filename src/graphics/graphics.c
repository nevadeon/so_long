/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/14 20:49:03 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game_visuals *graphs)
{
	mlx_delete_image(graphs->mlx, graphs->menu_bg);
	mlx_delete_image(graphs->mlx, graphs->exit_bt);
	mlx_delete_image(graphs->mlx, graphs->start_bt);
	mlx_delete_image(graphs->mlx, graphs->foreground);
	mlx_terminate(graphs->mlx);
}

void	init_select_anim(t_game_visuals *graphs)
{
	t_sprite	select_sprite;

	select_sprite = (t_sprite){
		.file_path = SELECT_SPRITE,
		.nb_frames = 3,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0,
	};
load_animation(graphs->mlx, &graphs->select_anim , &select_sprite);
}

void	init_graphics(t_game_visuals *graphs)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*graphs = (t_game_visuals){
		.mlx = mlx,
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.menu_bg = load_png(mlx, MENU_BACKGROUND),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
	init_select_anim(graphs);
}

void	display_menu(t_game_visuals *graphs)
{
	int	x;
	int	y;

	print_image(graphs->mlx, graphs->menu_bg, 0, 0);
	x = graphs->mlx->width / 2 - graphs->start_bt->width / 2;
	y = graphs->mlx->height / 100 * 40;
	print_image(graphs->mlx, graphs->start_bt, x, y);
	x = graphs->mlx->width / 2 - graphs->exit_bt->width / 2;
	y = graphs->mlx->height / 100 * 60;
	print_image(graphs->mlx, graphs->exit_bt, x, y);
	print_image(graphs->mlx, graphs->select_anim.frames[0], 0, 0);
}