/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:52:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/16 16:44:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_animation(mlx_image_t *render_layer, t_animation *a, double dt)
{
	a->time_counter += 1000 * dt;
	if (a->time_counter > a->refresh_time)
	{
		a->time_counter -= a->refresh_time;
		if (a->frames[a->current_frame] == NULL)
			a->current_frame = 0;
		copy_image(render_layer, a->frames[a->current_frame], 0, 0);
		a->current_frame++;
	}
}

void	update_graphics(void *param)
{
	t_game_visuals	*gv;

	gv = (t_game_visuals *) param;

	update_animation(gv->background, &gv->menu_bg_anim, gv->mlx->delta_time);
}

void	so_long(t_game_map *map, t_game_visuals *gv)
{
	(void)map;
	init_graphics(gv);
	if (mlx_image_to_window(gv->mlx, gv->background, 0, 0) == -1)
		handle_mlx_error();
	print_image(gv->mlx, gv->background, 0, 0);
	mlx_set_instance_depth(gv->background->instances, 1);
	print_image(gv->mlx, gv->foreground, 0, 0);
	mlx_loop_hook(gv->mlx, update_graphics, gv);
	mlx_loop(gv->mlx);
}
