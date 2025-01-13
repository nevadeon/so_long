#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game_env	*env;

	env = param;
	if (env->game_status == PLAYING)
		in_game_key_logic(keydata, env);
	else if (env->game_status == IN_MENU)
		in_menu_key_logic(keydata, env);
}
