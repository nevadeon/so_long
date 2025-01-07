#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <time.h>

# define WINDOW_TITLE "so_long"
# define WIDTH 	1309
# define HEIGHT	995

# define PATH_MENUBG_SPRITE	"assets/menu/menu_background_sprite.png"
# define PATH_SELECT_SPRITE	"assets/menu/select_sprite.png"
# define PATH_START_BUTTON	"assets/menu/start.png"
# define PATH_EXIT_BUTTON	"assets/menu/exit.png"
# define PATH_IDLE_KNIGHT_SPRITE "assets/knight/idle_knight.png"
# define PATH_MOVING_KNIGHT_SPRITE "assets/knight/moving_knight.png"

typedef enum e_xy
{
	X = 0,
	Y = 1
}	t_xy;

typedef enum e_game_status
{
	IN_MENU,
	PLAYING,
	TRANSITION
}	t_game_status;

typedef enum e_knight_status
{
	IDLE,
	MOVING
}	t_knight_status;

typedef enum e_menu_buttons
{
	BTN_START,
	BTN_EXIT,
	BTN_TEST,
	BTN_MAX
}	t_menu_buttons;

typedef struct s_coords
{
	size_t	x;
	size_t	y;
}	t_coords;

typedef struct s_sprite
{
	char		*file_path;
	mlx_image_t	*image;
	size_t		nb_frames;
	size_t		nb_collumns;
	size_t		nb_rows;
	size_t		frame_width;
	size_t		frame_height;
	size_t		padding_x;
	size_t		padding_y;
}	t_sprite;

typedef struct s_animation
{
	mlx_image_t	**frames;
	mlx_image_t	*render_layer;
	size_t		current_frame;
	size_t		update_delay_ms;
	double		time_counter_ms;
	bool		force_refresh;
}	t_animation;

typedef struct s_game_env
{
	mlx_t			*mlx;
	mlx_image_t		*start_bt;
	mlx_image_t		*exit_bt;
	mlx_image_t		*background;
	mlx_image_t		*foreground;
	t_animation		select_anim;
	t_animation		menu_bg_anim;
	t_animation		idle_knight;
	t_animation		moving_knight;
	t_game_status	game_status;
	t_knight_status	knight_status;
	t_menu_buttons	selected_button;
}	t_game_env;

void		init_graphics(t_game_env *env);
void		init_menu_bg_anim(t_game_env *env);
void		init_select_anim(t_game_env *env);
void		free_graphics(t_game_env *env);

void		user_key_press(mlx_key_data_t keydata, void *param);
void		menu_key_press(mlx_key_data_t keydata, t_game_env *env);
void		playing_key_press(mlx_key_data_t keydata, t_game_env *env);
void		update_game(void *param);
void		display_menu(t_game_env *env);

size_t		get_button_coords(t_menu_buttons button, t_xy xy);

mlx_image_t	*new_image(mlx_t *mlx, size_t width, size_t height);
mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path);
void		copy_image(mlx_image_t *dest, mlx_image_t *src,
				size_t x_start, size_t y_start);
void		clear_image(mlx_image_t *image);
void		load_animation(mlx_t *mlx, t_animation *a, t_sprite *s);
void		image_to_window(mlx_t *mlx, mlx_image_t *image,
				size_t x, size_t y);
uint32_t	get_pixel_value(mlx_image_t *img, size_t x, size_t y);

#endif
