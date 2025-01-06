/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:57:00 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:00 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game_visuals *gv)
{
	mlx_terminate(gv->mlx);
	free(gv->select_anim.frames);
	free(gv->menu_bg_anim.frames);
}
