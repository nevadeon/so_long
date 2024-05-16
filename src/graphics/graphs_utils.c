/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/16 14:33:07 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game_visuals *gv)
{
	mlx_terminate(gv->mlx);
	free(gv->select_anim.frames);
	free(gv->menu_bg.frames);
}
