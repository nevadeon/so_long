#include "so_long.h"

bool	is_moving(mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_UP)
		|| mlx_is_key_down(mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		return (true);
	return (false);
}

void	update_game(void *param)
{
	t_game_env	*env;

	env = (t_game_env *) param;
	if (env->game_status == IN_MENU)
	{
		env->select_anim.dest_x = get_button_coords(env->selected_button, X);
		env->select_anim.dest_y = get_button_coords(env->selected_button, Y);
		update_animation(&env->select_anim, env->mlx->delta_time);
		update_animation(&env->menu_bg_anim, env->mlx->delta_time);
	}
	else if (env->game_status == PLAYING)
	{
		if (is_moving(env->mlx))
			update_animation(&env->moving_knight, env->mlx->delta_time);
		else
			update_animation(&env->idle_knight, env->mlx->delta_time);
	}
}
