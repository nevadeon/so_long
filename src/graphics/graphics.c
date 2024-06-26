/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/23 18:36:18 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const uint32_t	_button_coords[][2] = {
{572, 585},
{572, 746}
};

void	update_animation(t_animation *a, double dt, uint32_t x, uint32_t y)
{
	a->time_counter += 1000 * dt;
	if (a->time_counter > a->refresh_time || a->force_refresh == true)
	{
		if (a->force_refresh == true)
		{
			a->force_refresh = false;
			clear_image(a->render_layer);
		}
		else
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
	x = _button_coords[gv->selected_button][X];
	y = _button_coords[gv->selected_button][Y];
	update_animation(&gv->select_anim, gv->mlx->delta_time, x, y);
	update_animation(&gv->menu_bg_anim, gv->mlx->delta_time, 0, 0);
}

void	display_menu(t_game_visuals *gv)
{
	uint32_t	x;
	uint32_t	y;

	image_to_window(gv->mlx, gv->menu_bg_anim.render_layer, 0, 0);
	x = _button_coords[BTN_START][X];
	y = _button_coords[BTN_START][Y];
	image_to_window(gv->mlx, gv->start_bt, x, y);
	x = _button_coords[BTN_EXIT][X];
	y = _button_coords[BTN_EXIT][Y];
	image_to_window(gv->mlx, gv->exit_bt, x, y);
	image_to_window(gv->mlx, gv->select_anim.render_layer, 0, 0);
}
