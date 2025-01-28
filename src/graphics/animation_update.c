#include "so_long.h"

static void	_render_image(t_animation a, uint32_t src_x, uint32_t src_y)
{
	uint32_t	pixel;
	uint32_t	x;
	uint32_t	y;

	y = 0;
	while (y < a.frame_height)
	{
		x = 0;
		while (x < a.frame_width)
		{
			if (a.is_mirrored == true)
				pixel = get_pixel_value(a.sprite_sheet, src_x - x, src_y + y);
			else
				pixel = get_pixel_value(a.sprite_sheet, src_x + x, src_y + y);
			mlx_put_pixel(a.render_layer, x + a.dest_x, y + a.dest_y, pixel);
			x++;
		}
		y++;
	}
}

static void	_render_animation(t_animation a)
{
	uint32_t	frame_index;
	uint32_t	columns;
	uint32_t	src_x;
	uint32_t	src_y;

	frame_index = a.start_frame + a.current_frame;
	columns = a.sprite_sheet->width / (a.frame_width + 2 * a.padding_x);
	src_x = (frame_index % columns)
		* (a.frame_width + 2 * a.padding_x)
		+ a.padding_x;
	src_y = (frame_index / columns)
		* (a.frame_height + 2 * a.padding_y)
		+ a.padding_y;
	if (src_x + a.frame_width > a.sprite_sheet->width
		|| src_y + a.frame_height > a.sprite_sheet->height
		|| a.dest_x + a.frame_width > a.render_layer->width
		|| a.dest_y + a.frame_height > a.render_layer->height)
		error(ERR_RENDER_INDEX);
	if (a.is_mirrored == true)
		src_x += a.frame_width;
	_render_image(a, src_x, src_y);
}

static void	_update_bounce_animation(t_animation *a)
{
	if (a->anim_type == BOUNCE_PLAYING_FORWARD)
	{
		if (a->current_frame == a->frame_count - 1)
		{
			a->anim_type = BOUNCE_PLAYING_BACKWARD;
			a->current_frame--;
		}
		else
			a->current_frame++;
	}
	else
	{
		if (a->current_frame == 0)
		{
			a->anim_type = BOUNCE_PLAYING_FORWARD;
			a->current_frame++;
		}
		else
			a->current_frame--;
	}
}

void	update_animation(t_animation *a, double deltatime_s)
{
	a->elapsed_time_ms += 1000 * deltatime_s;
	if (a->needs_clear_refresh)
	{
		a->needs_clear_refresh = false;
		clear_image(a->render_layer);
		_render_animation(*a);
	}
	else if (a->elapsed_time_ms >= a->frame_duration_ms)
	{
		a->elapsed_time_ms -= a->frame_duration_ms;
		if (a->anim_type != CLASSIC)
			_update_bounce_animation(a);
		else
			a->current_frame = (a->current_frame + 1) % a->frame_count;
		_render_animation(*a);
	}
}
