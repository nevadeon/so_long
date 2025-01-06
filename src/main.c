#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_visuals	gv;

	parse_args(argc, argv, &map);
	init_graphics(&gv);
	display_menu(&gv);
	mlx_key_hook(gv.mlx, user_key_press, &gv);
	mlx_loop_hook(gv.mlx, update_graphics, &gv);
	mlx_loop(gv.mlx);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
