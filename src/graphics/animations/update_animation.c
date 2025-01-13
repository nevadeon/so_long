#include "so_long.h"

static void	_update_bounce_animation(t_animation *a)
{
	if (a->playing_in_reverse)
	{
		if (a->current_frame == 0)
		{
			a->playing_in_reverse = false;
			a->current_frame++;
		}
		else
			a->current_frame--;
	}
	else
	{
		if (a->current_frame == a->frame_count - 1)
		{
			a->playing_in_reverse = true;
			a->current_frame--;
		}
		else
			a->current_frame++;
	}
}

void	update_animation(t_animation *a, double deltatime_s)
{
	a->elapsed_time_ms += 1000 * deltatime_s;
	if (a->elapsed_time_ms >= a->frame_duration_ms || a->needs_refresh == true)
	{
		if (a->needs_refresh == true)
		{
			clear_image(a->render_layer);
			a->needs_refresh = false;
		}
		else
			a->elapsed_time_ms -= a->frame_duration_ms;
		if (a->bounce == true)
			_update_bounce_animation(a);
		else
			a->current_frame = (a->current_frame + 1) % a->frame_count;
		render_animation(*a);
	}
}
