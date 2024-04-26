/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:21:28 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/26 14:39:05 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../include/MLX42.h"

// void	ft_hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		image->instances[0].y -= 5;
// 	else if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		image->instances[0].y += 5;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		image->instances[0].x -= 5;
// 	else if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		image->instances[0].x += 5;
// }

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	game(t_envir *env)
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	(void)env;
	// mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(960, 995, "so_long", true);
	// image = mlx_new_image(mlx, 10000, 10000);
	texture = mlx_load_png("textures/ground.png");
	image = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
