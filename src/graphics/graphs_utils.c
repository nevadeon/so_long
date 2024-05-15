/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphs_utilsls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 17:57:23 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_graphics(t_game_visuals *graphs)
{
	mlx_delete_image(graphs->mlx, graphs->menu_bg);
	mlx_delete_image(graphs->mlx, graphs->exit_bt);
	mlx_delete_image(graphs->mlx, graphs->start_bt);
	mlx_delete_image(graphs->mlx, graphs->foreground);
	mlx_terminate(graphs->mlx);
}
