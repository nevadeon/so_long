#ifndef ERRORS_H
# define ERRORS_H

# include "so_long.h"
# include "MLX42.h"   //graphic lib
# include "libndav.h"
# include "graphics.h"
# include "errors.h"

/**
 * @brief Error codes that are used to identify corresponding error message and
 * are also used as exit program value
 */
typedef enum e_error
{
	OK = 0,
	ERR_ARGS,
	ERR_NAME,
	ERR_EXT,
	ERR_OPEN,
	ERR_EMPTY_MAP,
	ERR_MAP_SIZE,
	ERR_RECT,
	ERR_WALL,
	ERR_CHAR,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COL,
	ERR_UNREACH,
	ERR_FRAME_DIMENSION,
	ERR_BUTTON_COORD,
	ERR_MAX
}	t_error;

/*==============================================================================
                                ERROR MANAGEMENT
==============================================================================*/

/**
 * @brief Take an error code and look in the error_message table for the
 * correspongind message
 *
 * @param error_code The error code
 * @return The corresponding error message
 */
const char	*get_error_message(t_error error_code);

/**
 * @brief Put an error mesage in the standard error file descriptor and exit
 * the program
 *
 * @param error_code The error code
 */
void		error(t_error error_code);

/**
 * @brief Print the global error variable of the mlx library and exit
 * the program
 */
void		handle_mlx_error(void);

#endif
