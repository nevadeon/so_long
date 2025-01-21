#include "so_long.h"

void	clear_image(mlx_image_t *image)
{
	memset(image->pixels, 0xFF000000,
		image->width * image->height * sizeof(int32_t));
}

// void	clear_image(mlx_image_t *image)
// {
// 	uint32_t	y;
// 	uint32_t	x;

// 	y = 0;
// 	while (y < image->height)
// 	{
// 		x = 0;
// 		while (x < image->width)
// 		{
// 			mlx_put_pixel(image, x, y, 0xFF000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }
