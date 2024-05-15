/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:16:12 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 20:46:10 by ndavenne         ###   ########.fr       */
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

void	print_image(mlx_t *mlx, mlx_image_t *image, uint32_t x, uint32_t y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
		handle_mlx_error();
}

void	copy_image(mlx_image_t *dest, mlx_image_t *src,
	uint32_t x_start, uint32_t y_start)
{
	uint32_t	pixel;
	uint32_t	x;
	uint32_t	y;

	x_start = 0;
	y_start = 0;
	y = 0;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			if (x < dest->width && y < dest->height)
			{
				pixel = get_pixel_value(src, x, y);
				mlx_put_pixel(dest, x, y, pixel);
			}
			x++;
		}
		y++;
	}
}
