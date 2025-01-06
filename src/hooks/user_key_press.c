#include "so_long.h"

void	user_key_press(mlx_key_data_t keydata, void *param)
{
	t_game_env	*env;

	env = param;
	if (env->game_status == PLAYING)
		game_logic(keydata, env);
	else if (env->game_status == IN_MENU)
		menu_logic(keydata, env);
}
