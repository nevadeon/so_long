#include "so_long.h"

void	update_animation(t_animation *a, double deltatime_s, size_t x, size_t y)
{
	a->time_counter_ms += 1000 * deltatime_s;
	if (a->time_counter_ms > a->update_delay_ms || a->force_refresh == true)
	{
		if (a->force_refresh == true)
		{
			a->force_refresh = false;
			clear_image(a->render_layer);
		}
		else
			a->time_counter_ms -= a->update_delay_ms;
		if (a->frames[a->current_frame] == NULL)
			a->current_frame = 0;
		copy_image(a->render_layer, a->frames[a->current_frame], x, y);
		a->current_frame++;
	}
}

void	update_graphics(void *param)
{
	t_game_visuals	*gv;
	size_t			x;
	size_t			y;

	gv = (t_game_visuals *) param;
	x = get_button_coords(gv->selected_button, X);
	y = get_button_coords(gv->selected_button, Y);
	update_animation(&gv->select_anim, gv->mlx->delta_time, x, y);
	update_animation(&gv->menu_bg_anim, gv->mlx->delta_time, 0, 0);
}

