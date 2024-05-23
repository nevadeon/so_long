/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:10:44 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/23 17:40:04 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_menu(mlx_key_data_t keydata, void *param)
{
	t_game_visuals	*gv;

	gv = param;
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
		gv->game_status = IN_MENU;
	if (gv->game_status == IN_MENU && keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_DOWN && gv->selected_button < BTN_MAX - 1)
		{
			gv->selected_button++;
			gv->select_anim.force_refresh = true;
		}
		else if (keydata.key == MLX_KEY_UP && gv->selected_button > 1)
		{
			gv->selected_button--;
			gv->select_anim.force_refresh = true;
		}
		else if (keydata.key == MLX_KEY_ENTER)
		{
			if (gv->selected_button == BTN_START)
				gv->game_status = PLAYING;
			if (gv->selected_button == BTN_EXIT)
				exit(OK);
		}
	}
}
