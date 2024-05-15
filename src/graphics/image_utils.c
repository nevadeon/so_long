/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:40:13 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/15 17:47:59 by ndavenne         ###   ########.fr       */
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

static uint32_t	_get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y)
{
	uint8_t	*pixel;

	if (x > img->width || y > img->height)
		return (0xFFFFFF00);
	pixel = img->pixels + (y * img->width + x) * sizeof(uint32_t);
	return (_get_rgba(*(pixel), *(pixel + 1), *(pixel + 2), *(pixel + 3)));
}
