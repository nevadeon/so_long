#include "so_long.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {
		[OK] = "Error\nHow the hell did you get this error message ?",
		[ERR_ARGS] = "Error\ntoo many arguments",
		[ERR_NAME] = "Error\nfile name too short",
		[ERR_EXT] = "Error\nincorrect file extension",
		[ERR_OPEN] = "Error\nFound no corresponding file",
		[ERR_EMPTY_MAP] = "Error\nEmpty map",
		[ERR_MAP_SIZE] = "Error\nMap is too big",
		[ERR_RECT] = "Error\nMap is not a rectangle\n",
		[ERR_WALL] = "Error\nOpening in exterior walls\n",
		[ERR_CHAR] = "Error\nMap contains an unexpected character\n",
		[ERR_PLAYER] = "Error\nMap must have exactly 1 player\n",
		[ERR_EXIT] = "Error\nMap must have exactly 1 exit\n",
		[ERR_COL] = "Error\nMap must have at least 1 collectible\n",
		[ERR_UNREACH] = "Error\nUnreachable exit or collectible\n",
		[ERR_FRAME_DIMENSION] = "Error\nThe dev is a fucking morron",
		[ERR_MAX] = "Error\nIndex is out of <char *error_message[]> boundaries",
	};

	if (error_code < 0 || error_code > ERR_MAX)
		return (message[ERR_MAX]);
	return (message[error_code]);
}

void	error(t_error error_code)
{
	ft_dputendl(STDERR_FILENO, get_error_message(error_code));
	exit(error_code);
}

void	handle_mlx_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
