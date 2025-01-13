#include "so_long.h"

mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path)
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;

	texture = mlx_load_png(file_path);
	if (!texture)
		handle_mlx_error();
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		handle_mlx_error();
	mlx_delete_texture(texture);
	return (image);
}
