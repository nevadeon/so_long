#include "so_long.h"

void	update_game(void *param)
{
	t_game_env		*env;
	static double	elapsed_time_ms = 0;

	env = (t_game_env *) param;
	if (env->game_status == IN_MENU)
	{
		env->select_anim.dest_x = get_button_coords(env->selected_button, X);
		env->select_anim.dest_y = get_button_coords(env->selected_button, Y);
		update_animation(&env->select_anim, env->mlx->delta_time);
		update_animation(&env->menu_bg_anim, env->mlx->delta_time);
	}
	else
	{
		elapsed_time_ms += env->mlx->delta_time * 1000;
		if (elapsed_time_ms >= 15)
		{
			update_positions(env);
			elapsed_time_ms -= 15;
		}
		if (env->player.is_moving)
			update_animation(&env->moving_knight, env->mlx->delta_time);
		else
			update_animation(&env->idle_knight, env->mlx->delta_time);
	}
}
