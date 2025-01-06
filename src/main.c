#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_env	env;

	parse_args(argc, argv, &map);
	init_graphics(&env);
	display_menu(&env);
	mlx_key_hook(env.mlx, user_key_press, &env);
	mlx_loop_hook(env.mlx, update_graphics, &env);
	mlx_loop(env.mlx);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
