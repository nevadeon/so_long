/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:06:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/02 17:14:12 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "graphics.h"

uint32_t	get_pixel(t_sprite *sprite, uint32_t x, uint32_t y)
{
	uint32_t	pixel;

	return (pixel);
}

void	add_frame(t_animation *anim, t_sprite *sprite,
	uint32_t x_start, uint32_t y_start)
{
	uint32_t	pixel;
	uint32_t	x_end;
	uint32_t	y_end;
	uint32_t	x;
	uint32_t	y;

	x_end = x_start + sprite->frame_width;
	y_end = y_start + sprite->frame_height;
	y = y_start;
	while (y < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			pixel = get_pixel(sprite, x_start + x, y_start + y);
			mlx_put_pixel(anim->frames[anim->current_frame], x, y, pixel);
			x++;
		}
		y++;
	}
}

t_animation	*slice_sprite(t_animation *anim, t_sprite *sprite)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	x;
	uint32_t	y;

	anim->current_frame = 0;
	i = 0;
	while (i < sprite->nb_rows)
	{
		j = 0;
		while (j < sprite->nb_collumns)
		{
			x = sprite->frame_width * i + sprite->padding_x * (i * 2 + 1);
			y = sprite->frame_height * j + sprite->padding_y * (j * 2 + 1);
			add_frame(anim, sprite, x, y);
			anim->current_frame += 1;
			j++;
		}
		i++;
	}
}

t_animation	*load_sprite(mlx_t *mlx, t_sprite *sprite)
{
	t_animation	*anim;

	anim->frames = (mlx_image_t *)
		calloc(sprite->nb_frames + 1, sizeof(mlx_image_t));
	sprite->img = load_png(mlx, sprite->file_path);
	slice_sprite(anim, sprite);
	mlx_delete_image(mlx, sprite->img);
	return (anim);
}
