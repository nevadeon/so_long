/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:13 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 18:55:40 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * In MLX42 Colors are as follows:
 * 
 * 0x|00|00|00|00
 *   |R |G |B |A 
 * 
 * R 0xFF000000
 * G 0x00FF0000
 * B 0x0000FF00
 * A 0x000000FF
 **/

static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	mlx_get_pixel(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t	*pixelstart;

	if (x > img->width || y > img->height)
		return (0xFF000000);
	pixelstart = img->pixels + (y * img->width + x) * sizeof(int32_t);
	return (get_rgba(*(pixelstart), *(pixelstart + 1),
			*(pixelstart + 2), *(pixelstart + 3)));
}

uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint32_t	pixel;

	if (x > img->width || y > img->height)
		return (0xFFFFFF00);
	ft_memcpy(&pixel, img->pixels[(y * img->width + x) * 4], sizeof(pixel));
	return (pixel);
}
