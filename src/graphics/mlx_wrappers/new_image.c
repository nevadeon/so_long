#include "so_long.h"

mlx_image_t	*new_image(mlx_t *mlx, size_t width, size_t height)
{
	mlx_image_t	*img;

	img = mlx_new_image(mlx, width, height);
	if (!img)
		handle_mlx_error();
	return (img);
}
