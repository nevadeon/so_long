#include "so_long.h"

void	free_graphics(t_game_visuals *gv)
{
	mlx_terminate(gv->mlx);
	free(gv->select_anim.frames);
	free(gv->menu_bg_anim.frames);
}
