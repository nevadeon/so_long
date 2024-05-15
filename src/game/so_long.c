/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:52:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:56 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_menu(t_game_visuals *graphs)
{
	uint32_t	x;
	uint32_t	y;

	x = graphs->mlx->width / 2 - graphs->menu_anim.frames[0]->width / 2;
	y = graphs->mlx->height / 2 - graphs->menu_anim.frames[0]->height / 2;
	print_image(graphs->mlx, graphs->menu_anim.frames[0], x, y);
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

void	so_long(t_game_map *map, t_game_visuals *graphs)
{
	(void)map;
	init_graphics(graphs);
	display_menu(graphs);
	mlx_loop(graphs->mlx);
}
