#include "so_long.h"

static void	_check_extension(char *filename)
{
	uint32_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		error(ERR_NAME);
	if (ft_memcmp(filename + len - 4, ".ber", 4))
		error(ERR_NAME);
}

static void	get_map_from_args(int argc, char *argv[], t_game_map *map)
{
	*map = (t_game_map){0};
	if (argc == 2)
	{
		_check_extension(argv[1]);
		map->grid = get_map(argv[1]);
	}
	else
		map->grid = get_map(DEFAULT_MAP_PATH);
}

t_game_map	process_args(int argc, char *argv[])
{
	t_game_map	map;
	t_error		error_code;

	map = (t_game_map){0};
	if (ft_strncmp(argv[0], "./so_long", 9) != 0)
		error(ERR_ARGV);
	if (argc > 2)
		error(ERR_ARGS);
	get_map_from_args(argc, argv, &map);
	if (map.grid == NULL)
		error(ERR_OPEN);
	error_code = parse_map(&map);
	if (error_code != OK)
	{
		ft_dputendl(STDERR_FILENO, get_error_message(error_code));
		if (map.width < 50 && map.height < 100)
			print_map(map.grid);
		free_map(map.grid);
		exit(error_code);
	}
	return (map);
}
