#include "so_long.h"

void	display_menu(t_game_env *env)
{
	image_to_window(env->mlx, env->menu_bg_anim.render_layer, 0, 0);
	image_to_window(env->mlx, env->start_bt,
		get_button_coords(BTN_START, X), get_button_coords(BTN_START, Y));
	image_to_window(env->mlx, env->exit_bt,
		get_button_coords(BTN_EXIT, X), get_button_coords(BTN_EXIT, Y));
	image_to_window(env->mlx, env->select_anim.render_layer, 0, 0);
}
