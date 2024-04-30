/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:22:20 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/30 19:36:49 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "MLX42.h"

const char	**pathp[] = {};

static void	error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	menu(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	mlx = mlx_init(WIDTH, HEIGHT, "So Loooong (gay) Bowser", false);
	if (!mlx)
		error();
	texture = mlx_load_png(MENU_BACKGROUND);
	if (!texture)
		error();
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		error();
	if (mlx_image_to_window(mlx, image, 0, 0) < 0)
		error();
	texture = mlx_load_png(START_BUTTON);
	if (!texture)
		error();
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		error();
	if (mlx_image_to_window(mlx, image, CENTER_X, 40 * PERCENT_Y) < 0)
		error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, image);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
