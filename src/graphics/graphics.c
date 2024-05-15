/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 14:07:15 by ndavenne         ###   ########.fr       */
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

void	init_graphics(t_game_visuals *graphs)
{
	mlx_t		*mlx;

	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, true);
	if (!mlx)
		handle_mlx_error();
	*graphs = (t_game_visuals){
		.mlx = mlx,
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.menu_bg = load_png(mlx, MENU_BACKGROUND),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
	init_menu_bg_anim(graphs);
	init_select_anim(graphs);
}

void	display_menu(t_game_visuals *graphs)
{
	uint32_t	x;
	uint32_t	y;

	x = graphs->mlx->width / 2 - graphs->menu_bg_anim.frames[0]->width / 2;
	y = graphs->mlx->height / 2 - graphs->menu_bg_anim.frames[0]->height / 2;
	print_image(graphs->mlx, graphs->menu_bg_anim.frames[0], x, y);
	x = graphs->mlx->width / 2 - graphs->start_bt->width / 2;
	y = graphs->mlx->height / 100 * 40;
	print_image(graphs->mlx, graphs->start_bt, x, y);
	x = graphs->mlx->width / 2 - graphs->exit_bt->width / 2;
	y = graphs->mlx->height / 100 * 60;
	print_image(graphs->mlx, graphs->exit_bt, x, y);
	// print_image(graphs->mlx, graphs->select_anim.frames[0], 0, 0);
	// print_image(graphs->mlx, graphs->select_anim.frames[1], 0, 150);
	// print_image(graphs->mlx, graphs->select_anim.frames[2], 0, 300);
}
