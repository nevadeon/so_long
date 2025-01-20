#include "so_long.h"

size_t	get_button_coords(t_menu_buttons button, t_coords_index index)
{
	static const size_t	button_coords[][2] = {\
		[BTN_START] = {572, 585}, \
		[BTN_EXIT] = {572, 746}, \
	};

	if (button > BTN_MAX || button < 0 || index > Y || index < X)
		error(ERR_BUTTON_INDEX);
	return (button_coords[button][index]);
}
