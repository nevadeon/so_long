/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:55:14 by nevadeon          #+#    #+#             */
/*   Updated: 2024/05/14 20:45:13 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_frame(t_animation *a, t_sprite *s, t_uint x_start, t_uint y_start)
{
	uint32_t	pixel;
	uint32_t	x_end;
	uint32_t	y_end;
	uint32_t	x;
	uint32_t	y;

	x_end = x_start + s->frame_width;
	y_end = y_start + s->frame_height;
	y = 0;
	while (y < s->frame_height)
	{
		x = 0;
		while (x < s->frame_width)
		{
			pixel = get_pixel_value(s->image, x_start + x, y_start + y);
			mlx_put_pixel(a->frames[a->current_frame], x, y, pixel);
			x++;
		}
		y++;
	}
}

void	slice_sprite(t_animation *a, t_sprite *s)
{
	uint32_t	i;
	uint32_t	j;
	uint32_t	x_start;
	uint32_t	y_start;

	a->current_frame = 0;
	j = 0;
	while (j < s->nb_rows)
	{
		i = 0;
		while (i < s->nb_collumns && a->current_frame < s->nb_frames)
		{
			x_start = s->frame_width * i + s->padding_x * (i * 2 + 1);
			y_start = s->frame_height * j + s->padding_y * (j * 2 + 1);
			add_frame(a, s, x_start, y_start);
			a->current_frame += 1;
			i++;
		}
		j++;
	}
}

t_error	parse_sprite(t_sprite *s)
{
	uint32_t	s_width;
	uint32_t	s_height;

	s_width = s->image->width;
	s_height = s->image->height;
	while (s_width >= s->frame_width + s->padding_x * 2)
	{
		s_width -= s->frame_width + s->padding_x * 2;
		s->nb_collumns += 1;
	}
	while (s_height >= s->frame_height + s->padding_y * 2)
	{
		s_height -= s->frame_height + s->padding_y * 2;
		s->nb_rows += 1;
	}
	if (s_width != 0 || s_height != 0)
		return (ERR_FRAME_DIMENSION);
	return (OK);
}

void	load_animation(mlx_t *mlx, t_animation *a, t_sprite *s)
{
	uint32_t	i;

	s->image = load_png(mlx, s->file_path);
	parse_sprite(s);
	a->frames = (mlx_image_t **)calloc(s->nb_frames + 1, sizeof(mlx_image_t *));
	i = 0;
	while (i < s->nb_frames)
	{
		a->frames[i] = new_image(mlx, s->frame_width, s->frame_height);
		i++;
	}
	a->frames[s->nb_frames] = NULL;
	slice_sprite(a, s);
	mlx_delete_image(mlx, s->image);
}
