/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:12 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/02 16:16:39 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "graphics.h"

mlx_image_t	*load_png(mlx_t	*mlx, char *file_path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(file_path);
	if (!texture)
		error();
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		error();
	mlx_delete_texture(texture);
	return (image);
}

mlx_image_t	*load_image(mlx_t *mlx, int width, int height)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		error();
	return (img);
}
