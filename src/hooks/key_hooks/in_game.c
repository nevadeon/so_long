#include "so_long.h"

void	in_game_key_logic(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		env->game_status = IN_MENU;
		env->menu_bg_anim.render_layer->enabled = true;
		env->start_bt->enabled = true;
		env->exit_bt->enabled = true;
		env->water->enabled=false;
		env->sand->enabled=false;
		env->select_anim.needs_refresh = true;
	}
}
