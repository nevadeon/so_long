/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/02 16:10:47 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "graphics.h"
#include "MLX42.h"

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	free_game(t_game *env)
{
	mlx_delete_image(env->mlx, env->menu_bg);
	mlx_delete_image(env->mlx, env->exit_bt);
	mlx_delete_image(env->mlx, env->start_bt);
	mlx_delete_image(env->mlx, env->foreground);
	mlx_terminate(env->mlx);
}

void	init_game(t_game *env)
{
	mlx_t		*mlx;
	t_sprite	*selected_button;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		error();
	*selected_button = (t_sprite){
		.file_path = SELECT_SPRITE,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0,
		.nb_frames = 3,
		.nb_collumns = 3,
		.nb_rows = 1
	};
	*env = (t_game){
		.mlx = mlx,
		.select_anim = load_sprite(mlx, selected_button),
		.foreground = load_image(mlx, WIDTH, HEIGHT),
		.menu_bg = load_png(mlx, MENU_BACKGROUND),
		.start_bt = load_png(mlx, START_BUTTON),
		.exit_bt = load_png(mlx, EXIT_BUTTON)
	};
}

void	display_menu(t_game *env)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (mlx_image_to_window(env->mlx, env->menu_bg, x, y) == -1)
		error();
	x = env->mlx->width / 2 - env->start_bt->width / 2;
	y = env->mlx->height / 100 * 40;
	if (mlx_image_to_window(env->mlx, env->start_bt, x, y) == -1)
		error();
	x = env->mlx->width / 2 - env->exit_bt->width / 2;
	y = env->mlx->height / 100 * 60;
	if (mlx_image_to_window(env->mlx, env->exit_bt, x, y) == -1)
		error();
}

int	game(void)
{
	t_game	env;

	init_game(&env);
	display_menu(&env);
	mlx_loop(env.mlx);
	free_game(&env);
	return (EXIT_SUCCESS);
}
