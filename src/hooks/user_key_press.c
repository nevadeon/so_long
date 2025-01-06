#include "so_long.h"

void	user_key_press(mlx_key_data_t keydata, void *param)
{
	t_game_visuals	*gv;

	gv = param;
	if (gv->game_status == PLAYING)
		game_logic(keydata, gv);
	else if (gv->game_status == IN_MENU)
		menu_logic(keydata, gv);
}
