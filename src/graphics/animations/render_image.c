#include "so_long.h"

void	render_image(t_animation a, size_t src_x, size_t src_y)
{
	uint32_t	pixel;
	size_t		x;
	size_t		y;

	y = 0;
	while (y < a.frame_height)
	{
		x = 0;
		while (x < a.frame_width)
		{
			if (a.mirrored == true)
				pixel = get_pixel_value2(a.sprite_sheet, src_x - x, src_y + y);
			else
				pixel = get_pixel_value2(a.sprite_sheet, src_x + x, src_y + y);
			mlx_put_pixel(a.render_layer, x + a.dest_x, y + a.dest_y, pixel);
			x++;
		}
		y++;
	}
}
