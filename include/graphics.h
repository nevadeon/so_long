#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "definitions.h"

typedef mlx_texture_t t_texture;

void		init_graphics(t_game_env *env, t_game_map map);
void		free_graphics(t_game_env *env);

void	display_map(t_game_env *env);
void	display_menu(t_game_env *env);

//hooks
void		key_hook(mlx_key_data_t keydata, void *param);
void		in_menu_key_logic(mlx_key_data_t keydata, t_game_env *env);
void		in_game_key_logic(mlx_key_data_t keydata, t_game_env *env);
void		update_game(void *param);

size_t		get_button_coords(t_menu_buttons button, t_coords_index xy);

//animations
void		update_animation(t_animation *a, double deltatime_s);
void		render_animation(t_animation a);
void		render_image(t_animation a, size_t src_x, size_t src_y);

//images
void		clear_image(mlx_image_t *image);
uint32_t	get_pixel_value(mlx_texture_t *img, size_t x, size_t y);

//mlx wrappers
t_texture	*texture_from_png(char *file_path);
mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path);
mlx_image_t	*new_image(mlx_t *mlx, size_t width, size_t height);
int32_t		image_to_window(mlx_t *mlx, mlx_image_t *image, size_t x, size_t y);

void	update_player_status(t_game_env *env, t_player_data *player);
void	update_knight_animation(t_game_env *env, t_player_data *player);

#endif
