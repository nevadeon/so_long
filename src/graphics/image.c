/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:12 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/04 01:46:35 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window(mlx_t *mlx, mlx_image_t *image, size_t x, size_t y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
		handle_mlx_error();
}

mlx_image_t	*new_image(mlx_t *mlx, size_t width, size_t height)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		handle_mlx_error();
	return (img);
}

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

void	copy_image(mlx_image_t *dest, mlx_image_t *src,
	size_t x_start, size_t y_start)
{
	uint32_t	pixel;
	size_t		x;
	size_t		y;

	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			if (x + x_start < dest->width && y + y_start < dest->height)
			{
				pixel = get_pixel_value(src, x, y);
				mlx_put_pixel(dest, x + x_start, y + y_start, pixel);
			}
			x++;
		}
		y++;
	}
}

void	clear_image(mlx_image_t *image)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < image->height)
	{
		x = 0;
		while (x < image->width)
		{
			mlx_put_pixel(image, x, y, 0xFF000000);
			x++;
		}
		y++;
	}
}
