/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 22:55:07 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game_visuals *graph)
{
	mlx_delete_image(graph->mlx, graph->menu_bg);
	mlx_delete_image(graph->mlx, graph->exit_bt);
	mlx_delete_image(graph->mlx, graph->start_bt);
	mlx_delete_image(graph->mlx, graph->foreground);
	mlx_terminate(graph->mlx);
}

void	init_graphics(t_game_visuals *graph)
{
	mlx_t		*mlx;
	t_sprite	*selected_button;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		mlx_error();
	*selected_button = (t_sprite){
		.file_path = SELECT_SPRITE,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0,
	};
	*graph = (t_game_visuals){
		.mlx = mlx,
		.select_anim = load_sprite(mlx, selected_button),
		.foreground = load_image(mlx, WIDTH, HEIGHT),
		.menu_bg = load_png(mlx, MENU_BACKGROUND),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
}

void	display_menu(t_game_visuals *graph)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (mlx_image_to_window(graph->mlx, graph->menu_bg, x, y) == -1)
		mlx_error();
	x = graph->mlx->width / 2 - graph->start_bt->width / 2;
	y = graph->mlx->height / 100 * 40;
	if (mlx_image_to_window(graph->mlx, graph->start_bt, x, y) == -1)
		mlx_error();
	x = graph->mlx->width / 2 - graph->exit_bt->width / 2;
	y = graph->mlx->height / 100 * 60;
	if (mlx_image_to_window(graph->mlx, graph->exit_bt, x, y) == -1)
		mlx_error();
}
