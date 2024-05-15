/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:51:09 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 14:03:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_select_anim(t_game_visuals *graphs)
{
	t_sprite	select_sprite;

	select_sprite = (t_sprite){
		.file_path = SELECT_SPRITE,
		.nb_frames = 3,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0
	};
	load_animation(graphs->mlx, &graphs->select_anim, &select_sprite);
}

void	init_menu_bg_anim(t_game_visuals *graphs)
{
	t_sprite	menu_bg_sprite;

	menu_bg_sprite = (t_sprite) {
		.file_path = MENU_SPRITE,
		.nb_frames = 24,
		.frame_width = 1309,
		.frame_height = 995,
		.padding_x = 10,
		.padding_y = 10
	};
	load_animation(graphs->mlx, &graphs->menu_bg_anim, &menu_bg_sprite);
}
