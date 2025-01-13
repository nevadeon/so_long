#include "so_long.h"

void	free_graphics(t_game_env *env)
{
	mlx_terminate(env->mlx);
}
