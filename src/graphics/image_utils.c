/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:13 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 02:33:12 by nevadeon         ###   ########.fr       */
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

uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t	*pixel_start;

	if (x > img->width || y > img->height)
		return (0xFFFFFF00);
	pixel_start = img->pixels + (y * img->width + x) * sizeof(uint32_t);
	return (get_rgba(*(pixel_start), *(pixel_start + 1),
			*(pixel_start + 2), *(pixel_start + 3)));
}

// uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y)
// {
// 	uint32_t	output;
// 	uint8_t		*pixel_start;

// 	if (x >= img->width || y >= img->height)
// 		return (0xFFFFFF00);
// 	pixel_start = img->pixels + (y * img->width + x) * sizeof(uint32_t);
// 	ft_memcpy(&output, pixel_start, 4);
// 	return (output);
// }
