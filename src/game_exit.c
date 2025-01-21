#include "so_long.h"

void	exit_game(t_game_env *env)
{
	mlx_delete_texture(env->menu_bg_anim.sprite_sheet);
	mlx_delete_texture(env->select_anim.sprite_sheet);
	mlx_delete_texture(env->moving_knight.sprite_sheet);
	mlx_delete_texture(env->idle_knight.sprite_sheet);
	mlx_terminate(env->mlx);
	free_map(env->map.grid);
	exit(EXIT_SUCCESS);
}
