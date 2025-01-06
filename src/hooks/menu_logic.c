#include "so_long.h"

void	menu_logic(mlx_key_data_t keydata, t_game_visuals *gv)
{
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_DOWN && gv->selected_button < BTN_MAX - 1)
			gv->selected_button++;
		else if (keydata.key == MLX_KEY_UP && gv->selected_button > 0)
			gv->selected_button--;
		else if (keydata.key == MLX_KEY_ENTER)
		{
			if (gv->selected_button == BTN_START)
			{
				gv->game_status = PLAYING;
				gv->start_bt->instances[0].enabled = false;
				gv->exit_bt->instances[0].enabled = false;
			}
			else if (gv->selected_button == BTN_EXIT)
				exit(OK);
		}
		gv->select_anim.force_refresh = true;
	}
}
