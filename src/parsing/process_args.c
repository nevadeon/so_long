#include "so_long.h"

static void	_check_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		error(ERR_NAME);
	if (memcmp(filename + len - 4, ".ber", 4))
		error(ERR_EXT);
}

t_game_map	process_args(int argc, char *argv[])
{
	t_game_map	map;
	t_error		error_code;

	map = (t_game_map){0};
	if (argc > 2)
		error(ERR_ARGS);
	if (argc == 2)
	{
		_check_extension(argv[1]);
		map.grid = get_map(argv[1]);
	}
	else
		map.grid = get_map(DEFAULT_MAP_PATH);
	if (map.grid == NULL)
		error(ERR_OPEN);
	error_code = parse_map(&map);
	if (error_code != OK)
	{
		ft_dputendl(STDERR_FILENO, get_error_message(error_code));
		if (error_code != ERR_MAP_SIZE)
			print_map(map.grid);
		free_map(map.grid);
		exit(error_code);
	}
	return (map);
}
