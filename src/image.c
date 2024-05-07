/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:12 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/07 14:04:14 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*load_png(mlx_t	*mlx, char *file_path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(file_path);
	if (!texture)
		handle_mlx_error();
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		handle_mlx_error();
	mlx_delete_texture(texture);
	return (image);
}

mlx_image_t	*new_image(mlx_t *mlx, uint32_t width, uint32_t height)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		handle_mlx_error();
	return (img);
}
