#include "so_long.h"

void	render_animation(t_animation a)
{
	size_t	frame_index;
	size_t	columns;
	size_t	src_x;
	size_t	src_y;

	frame_index = a.start_frame + a.current_frame;
	columns = a.sprite_sheet->width / (a.frame_width + 2 * a.padding_x);
	src_x = (frame_index % columns)
		* (a.frame_width + 2 * a.padding_x)
		+ a.padding_x;
	src_y = (frame_index / columns)
		* (a.frame_height + 2 * a.padding_y)
		+ a.padding_y;
	if (src_x + a.frame_width > a.sprite_sheet->width
		|| src_y + a.frame_height > a.sprite_sheet->height
		|| a.dest_x + a.frame_width > a.render_layer->width
		|| a.dest_y + a.frame_height > a.render_layer->height)
		error(ERR_RENDER_COORD);
	if (a.mirrored == true)
		src_x += a.frame_width;
	render_image(a, src_x, src_y);
}
