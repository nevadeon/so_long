/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:52:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/17 15:28:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_animation(t_animation *a, double dt, uint32_t x, uint32_t y)
{
	a->time_counter += 1000 * dt;
	if (a->time_counter > a->refresh_time)
	{
		a->time_counter -= a->refresh_time;
		if (a->frames[a->current_frame] == NULL)
			a->current_frame = 0;
		copy_image(a->render_layer, a->frames[a->current_frame], x, y);
		a->current_frame++;
	}
}

void	update_graphics(void *param)
{
	t_game_visuals	*gv;
	uint32_t		x;
	uint32_t		y;

	gv = (t_game_visuals *) param;
	update_animation(&gv->menu_bg_anim, gv->mlx->delta_time, 0, 0);
	x = gv->mlx->width / 100 * 52 - gv->start_bt->width / 2;
	y = gv->mlx->height / 100 * 77 - gv->start_bt->width / 2;
	update_animation(&gv->select_anim, gv->mlx->delta_time, x, y);
}

void	display_menu(t_game_visuals *gv)
{
	uint32_t	x;
	uint32_t	y;

	image_to_window(gv->mlx, gv->menu_bg_anim.render_layer, 0, 0);
	image_to_window(gv->mlx, gv->select_anim.render_layer, 0, 0);
	x = gv->mlx->width / 100 * 52 - gv->start_bt->width / 2;
	y = gv->mlx->height / 100 * 77 - gv->start_bt->width / 2;
	image_to_window(gv->mlx, gv->start_bt, x, y);
	y = gv->mlx->height / 100 * 95 - gv->start_bt->width / 2;
	image_to_window(gv->mlx, gv->exit_bt, x, y);
	// gv->start_bt->instances[0].z = 1;
	// gv->exit_bt->instances[0].z = 2;
}

void	so_long(t_game_map *map, t_game_visuals *gv)
{
	(void)map;
	init_graphics(gv);
	display_menu(gv);
	mlx_loop_hook(gv->mlx, update_graphics, gv);
	mlx_loop(gv->mlx);
}
