#include "so_long.h"

size_t	get_button_coords(t_menu_buttons button, t_xy xy)
{
	static const size_t	button_coords[][2] = {\
		[BTN_START] = {572, 585}, \
		[BTN_EXIT] = {572, 746}, \
		[BTN_TEST] = {200, 746} \
	};

	if (button > BTN_MAX || button < 0 || xy > Y || xy < X)
		error(ERR_BUTTON_COORD);
	return (button_coords[button][xy]);
}
