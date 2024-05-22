/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:46:30 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/22 12:58:52 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# define WINDOW_TITLE "so_long"
# define WIDTH 	1309
# define HEIGHT	995

# define PATH_MENUBG_SPRITE	"assets/menu/menu_background_sprite.png"
# define PATH_SELECT_SPRITE	"assets/menu/select_sprite.png"
# define PATH_START_BUTTON	"assets/menu/start.png"
# define PATH_EXIT_BUTTON	"assets/menu/exit.png"

# define X 0
# define Y 1

typedef enum e_game_status
{
	IN_MENU,
	PLAYING,
	TRANSITION
}	t_game_status;

typedef enum e_menu_buttons
{
	BTN_MIN,
	BTN_START,
	BTN_EXIT,
	BTN_MAX
}	t_menu_buttons;

typedef uint32_t	t_uint;

typedef struct s_sprite
{
	char		*file_path;
	mlx_image_t	*image;
	uint32_t	nb_frames;
	uint32_t	nb_collumns;
	uint32_t	nb_rows;
	uint32_t	frame_width;
	uint32_t	frame_height;
	uint32_t	padding_x;
	uint32_t	padding_y;
}	t_sprite;

typedef struct s_animation
{
	mlx_image_t	**frames;
	mlx_image_t	*render_layer;
	uint32_t	current_frame;
	uint32_t	refresh_time;
	double		time_counter;
	bool		force_refresh;
}	t_animation;

typedef struct s_game_visuals
{
	mlx_t			*mlx;
	mlx_image_t		*start_bt;
	mlx_image_t		*exit_bt;
	t_animation		select_anim;
	t_animation		menu_bg_anim;
	t_game_status	game_status;
	t_menu_buttons	selected_button;
}	t_game_visuals;

void		init_graphics(t_game_visuals *gv);
void		init_menu_bg_anim(t_game_visuals *gv);
void		init_select_anim(t_game_visuals *gv);

void		update_menu(mlx_key_data_t keydata, void *param);
void		update_graphics(void *param);
void		display_menu(t_game_visuals *gv);

void		free_graphics(t_game_visuals *gv);
void		copy_image(mlx_image_t *dest, mlx_image_t *src,
				uint32_t x_start, uint32_t y_start);
void		clear_image(mlx_image_t *image);

mlx_image_t	*new_image(mlx_t *mlx, uint32_t width, uint32_t height);
mlx_image_t	*load_png(mlx_t	*mlx, char *file_path);
void		load_animation(mlx_t *mlx, t_animation *a, t_sprite *s);
void		image_to_window(mlx_t *mlx, mlx_image_t *image,
				uint32_t x, uint32_t y);

uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y);

#endif