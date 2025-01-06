#include "so_long.h"

void	game_logic(mlx_key_data_t keydata, t_game_visuals *gv)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		gv->game_status = IN_MENU;
		gv->start_bt->instances[0].enabled = true;
		gv->exit_bt->instances[0].enabled = true;
	}
}
