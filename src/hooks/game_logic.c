#include "so_long.h"

void	game_logic(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		env->game_status = IN_MENU;
		env->start_bt->instances[0].enabled = true;
		env->exit_bt->instances[0].enabled = true;
	}
}
