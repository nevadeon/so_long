/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:52:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/17 22:31:56 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const uint32_t	_select_coords[][2] = {
{0, 0},
{572, 585},
{572, 746}
};

void	update_animation(t_animation *a, double dt, uint32_t x, uint32_t y)
{
	a->time_counter += 1000 * dt;
	if (a->time_counter > a->refresh_time)
	{
		a->time_counter -= a->refresh_time;
		if (a->frames[a->current_frame] == NULL)
			a->current_frame = 0;
		clear_image(a->render_layer);
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
	if (gv->game_status == IN_MENU)
	{
		if (mlx_is_key_down(gv->mlx, MLX_KEY_DOWN)
			&& gv->selected_button < SELECT_MAX - 1)
			gv->selected_button += 1;
		if (mlx_is_key_down(gv->mlx, MLX_KEY_UP)
			&& gv->selected_button > SELECT_MIN + 1)
			gv->selected_button -= 1;
		if (mlx_is_key_down(gv->mlx, MLX_KEY_ENTER)
			&& gv->selected_button == SELECT_EXIT)
			exit(OK);
	}
	x = _select_coords[gv->selected_button][X];
	y = _select_coords[gv->selected_button][Y];
	update_animation(&gv->select_anim, gv->mlx->delta_time, x, y);
	update_animation(&gv->menu_bg_anim, gv->mlx->delta_time, 0, 0);
}

void	display_menu(t_game_visuals *gv)
{
	uint32_t	x;
	uint32_t	y;

	image_to_window(gv->mlx, gv->menu_bg_anim.render_layer, 0, 0);
	x = _select_coords[SELECT_START][X];
	y = _select_coords[SELECT_START][Y];
	image_to_window(gv->mlx, gv->start_bt, x, y);
	x = _select_coords[SELECT_EXIT][X];
	y = _select_coords[SELECT_EXIT][Y];
	image_to_window(gv->mlx, gv->exit_bt, x, y);
	image_to_window(gv->mlx, gv->select_anim.render_layer, 0, 0);
}

void	so_long(t_game_map *map, t_game_visuals *gv)
{
	(void)map;
	init_graphics(gv);
	display_menu(gv);
	mlx_loop_hook(gv->mlx, update_graphics, gv);
	mlx_loop(gv->mlx);
}
