#include "so_long.h"

void	playing_key_press(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		env->game_status = IN_MENU;
		env->start_bt->instances[0].enabled = true;
		env->exit_bt->instances[0].enabled = true;
		env->menu_bg_anim.render_layer->instances[0].enabled = true;
		env->select_anim.needs_refresh = true;
	}
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_LEFT)
		{
			env->idle_knight.mirrored = true;
			env->moving_knight.mirrored = true;
		}
		if (keydata.key == MLX_KEY_RIGHT)
		{
			env->idle_knight.mirrored = false;
			env->moving_knight.mirrored = false;
		}
	}
}
