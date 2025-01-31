#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_env	env;
	t_game_map	map;

	map = process_args(argc, argv);
	init_graphics(&env, map);
	start_game(&env);
	mlx_key_hook(env.mlx, key_hook, &env);
	mlx_loop_hook(env.mlx, update_game, &env);
	mlx_loop(env.mlx);
	exit_game(&env);
	return (EXIT_SUCCESS);
}
