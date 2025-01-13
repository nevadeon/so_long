#include "so_long.h"

mlx_texture_t	*texture_from_png(char *file_path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(file_path);
	if (!texture)
		handle_mlx_error();
	return (texture);
}
