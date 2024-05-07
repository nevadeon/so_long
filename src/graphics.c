/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/07 14:04:14 by ndavenne         ###   ########.fr       */
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
	t_sprite	*selected_button;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*selected_button = (t_sprite){
		.file_path = SELECT_SPRITE,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0,
	};
	*graphs = (t_game_visuals){
		.mlx = mlx,
		.select_anim = load_animation(mlx, selected_button),
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.menu_bg = load_png(mlx, MENU_BACKGROUND),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
}

void	display_menu(t_game_visuals *graphs)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (mlx_image_to_window(graphs->mlx, graphs->menu_bg, x, y) == -1)
		handle_mlx_error();
	x = graphs->mlx->width / 2 - graphs->start_bt->width / 2;
	y = graphs->mlx->height / 100 * 40;
	if (mlx_image_to_window(graphs->mlx, graphs->start_bt, x, y) == -1)
		handle_mlx_error();
	x = graphs->mlx->width / 2 - graphs->exit_bt->width / 2;
	y = graphs->mlx->height / 100 * 60;
	if (mlx_image_to_window(graphs->mlx, graphs->exit_bt, x, y) == -1)
		handle_mlx_error();
}
