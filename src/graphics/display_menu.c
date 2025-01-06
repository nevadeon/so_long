#include "so_long.h"

void	display_menu(t_game_visuals *gv)
{
	image_to_window(gv->mlx, gv->menu_bg_anim.render_layer, 0, 0);
	image_to_window(gv->mlx, gv->start_bt,
		get_button_coords(BTN_START, X), get_button_coords(BTN_START, Y));
	image_to_window(gv->mlx, gv->exit_bt,
		get_button_coords(BTN_EXIT, X), get_button_coords(BTN_EXIT, Y));
	image_to_window(gv->mlx, gv->select_anim.render_layer, 0, 0);
}
