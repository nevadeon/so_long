/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 17:52:10 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 20:42:22 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_graphics(void *param)
{
	t_game_visuals	*gv;

	gv = (t_game_visuals *) param;
	if (gv->menu_bg.frames[gv->menu_bg.current] == NULL)
		gv->menu_bg.current = 0;
	copy_image(gv->background, gv->menu_bg.frames[gv->menu_bg.current], 0, 0);
	gv->menu_bg.current++;
}

void	so_long(t_game_map *map, t_game_visuals *gv)
{
	(void)map;
	init_graphics(gv);
	if (mlx_image_to_window(gv->mlx, gv->background, 0, 0) == -1)
		handle_mlx_error();
	print_image(gv->mlx, gv->background, 0, 0);
	mlx_set_instance_depth(gv->background->instances, 1);
	// print_image(gv->mlx, gv->foreground, 0, 0);
	mlx_loop_hook(gv->mlx, update_graphics, gv);
	mlx_loop(gv->mlx);
}
