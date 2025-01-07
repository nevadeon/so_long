#include "so_long.h"

void	menu_key_press(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_DOWN && env->selected_button < BTN_MAX - 1)
			env->selected_button++;
		else if (keydata.key == MLX_KEY_UP && env->selected_button > 0)
			env->selected_button--;
		else if (keydata.key == MLX_KEY_ENTER)
		{
			if (env->selected_button == BTN_START)
			{
				env->game_status = PLAYING;
				env->start_bt->instances[0].enabled = false;
				env->exit_bt->instances[0].enabled = false;
				env->menu_bg_anim.render_layer->instances[0].enabled = false;
			}
			else if (env->selected_button == BTN_EXIT)
				exit(OK);
		}
		env->select_anim.force_refresh = true;
	}
}
