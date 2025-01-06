#include "so_long.h"

void	display_menu(t_game_visuals *gv)
{
	size_t	x;
	size_t	y;

	image_to_window(gv->mlx, gv->menu_bg_anim.render_layer, 0, 0);
	x = get_button_coords(BTN_START, X);
	y = get_button_coords(BTN_START, Y);
	image_to_window(gv->mlx, gv->start_bt, x, y);
	x = get_button_coords(BTN_EXIT, X);
	y = get_button_coords(BTN_EXIT, Y);
	image_to_window(gv->mlx, gv->exit_bt, x, y);
	image_to_window(gv->mlx, gv->select_anim.render_layer, 0, 0);
}
