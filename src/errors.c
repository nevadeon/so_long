#include "so_long.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {\
		[OK] = "How the hell did you get this error message ?", \
		[ERR_ARGS] = "too many arguments", \
		[ERR_NAME] = "incorrect file name or extension", \
		[ERR_OPEN] = "Found no corresponding file", \
		[ERR_EMPTY_MAP] = "Empty map", \
		[ERR_RECT] = "Map is not a rectangle", \
		[ERR_WALL] = "Opening in exterior walls", \
		[ERR_CHAR] = "Map contains an unexpected character", \
		[ERR_PLAYER] = "Map must have exactly 1 player", \
		[ERR_EXIT] = "Map must have exactly 1 exit", \
		[ERR_COL] = "Map must have at least 1 collectible", \
		[ERR_UNREACH] = "Unreachable exit or collectible", \
		[ERR_BUTTON_INDEX] = "Get_button_coords() was called with inv index", \
		[ERR_RENDER_INDEX] = "Render_animation() was called with inv index", \
		[ERR_MAX_INDEX] = "Get_error_message() was called with invalid index", \
		[ERR_ARGV] = "Go in the right folder you dumbass" \
	};

	if (error_code < 0 || error_code > ERR_MAX_INDEX)
		return (message[ERR_MAX_INDEX]);
	return (message[error_code]);
}

void	error(t_error error_code)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", get_error_message(error_code));
	exit(error_code);
}

void	handle_mlx_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
