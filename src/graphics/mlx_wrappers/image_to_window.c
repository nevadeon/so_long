#include "so_long.h"

int32_t	image_to_window(mlx_t *mlx, mlx_image_t *image, uint32_t x, uint32_t y)
{
	int32_t	return_value;

	return_value = mlx_image_to_window(mlx, image, x, y);
	if (return_value == -1)
		handle_mlx_error();
	return (return_value);
}
