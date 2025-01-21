#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "definitions.h"

typedef mlx_texture_t	t_texture;

void		init_graphics(t_game_env *env, t_game_map map);

uint32_t	get_button_coords(t_menu_buttons button, t_coords_index xy);
void		update_animation(t_animation *a, double deltatime_s);
void		clear_image(mlx_image_t *image);
uint32_t	get_pixel_value(mlx_texture_t *img, uint32_t x, uint32_t y);

//mlx wrappers
t_texture	*texture_from_png(char *file_path);
mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path);
mlx_image_t	*new_image(mlx_t *mlx, uint32_t width, uint32_t height);
int32_t		image_to_window(\
						mlx_t *mlx, mlx_image_t *image, uint32_t x, uint32_t y);


#endif
