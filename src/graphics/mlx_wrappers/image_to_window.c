#include "so_long.h"

void	image_to_window(mlx_t *mlx, mlx_image_t *image, size_t x, size_t y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
		handle_mlx_error();
}
