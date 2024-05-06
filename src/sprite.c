/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:55:14 by nevadeon          #+#    #+#             */
/*   Updated: 2024/05/06 16:40:11 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "graphics.h"
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
	y = y_start;
	while (y < y_end)
	{
		x = x_start;
		while (x < x_end)
		{
			pixel = get_pixel_value(s->image, x_start + x, y_start + y);
			mlx_put_pixel(a->frames[a->current_frame], x, y, pixel);
			x++;
		}
		y++;
	}
}

t_animation	*slice_sprite(t_animation *a, t_sprite *s)
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
		while (i < s->nb_collumns)
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
	int	width;
	int	height;

	width = s->frame_width;
	height = s->frame_height;
	while (width > 0)
	{
		width -= s->frame_width + s->padding_x * 2;
		s->nb_collumns += 1;
	}
	while (height > 0)
	{
		height -= s->frame_height + s->padding_y * 2;
		s->nb_rows += 1;
	}
	s->nb_frames = s->nb_rows * s->nb_collumns;
	if (width != 0 || height != 0)
		return (ERR_FRAME_DIMENSION);
	return (OK);
}

t_animation	*load_sprite(mlx_t *mlx, t_sprite *s)
{
	t_animation	*a;

	s->image = load_png(mlx, s->file_path);
	if (parse_sprite(s))
		return (NULL);
	a->frames = (mlx_image_t *) calloc(s->nb_frames + 1, sizeof(mlx_image_t));
	slice_sprite(a, s);
	mlx_delete_image(mlx, s->image);
	return (a);
}
