#include "so_long.h"

static void	update_selected_button(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_DOWN && env->selected_button < BTN_MAX - 1)
		{
			env->select_anim.needs_refresh = true;
			env->selected_button++;
		}
		else if (keydata.key == MLX_KEY_UP && env->selected_button > 0)
		{
			env->select_anim.needs_refresh = true;
			env->selected_button--;
		}
	}
}

void	in_menu_key_logic(mlx_key_data_t keydata, t_game_env *env)
{
	update_selected_button(keydata, env);
	if (keydata.key == MLX_KEY_ENTER)
	{
		if (env->selected_button == BTN_START)
		{
			env->game_status = PLAYING;
			env->menu_bg_anim.render_layer->enabled = false;
			env->start_bt->enabled = false;
			env->exit_bt->enabled = false;
			env->sand->enabled = true;
			env->water->enabled = true;
			env->idle_knight.needs_refresh = true;
		}
		else if (env->selected_button == BTN_EXIT)
			exit(OK);
	}
}
