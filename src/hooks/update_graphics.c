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
	t_game_env	*env;
	size_t		x;
	size_t		y;

	env = (t_game_env *) param;
	if (env->game_status == IN_MENU)
	{
		x = get_button_coords(env->selected_button, X);
		y = get_button_coords(env->selected_button, Y);
		update_animation(&env->select_anim, env->mlx->delta_time, x, y);
		update_animation(&env->menu_bg_anim, env->mlx->delta_time, 0, 0);
	}
}
