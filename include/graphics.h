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

typedef enum e_coords_index
{
	X = 0,
	Y = 1
}	t_coords_index;

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
	BTN_MAX
}	t_menu_buttons;

typedef struct s_animation{
	mlx_texture_t	*sprite_sheet;		// Texture containing all frames of the animation
	mlx_image_t		*render_layer;		// The image that is displayed on screen
	size_t			dest_x;				// X position in the render image
	size_t			dest_y;				// Y position in the render image
	size_t			frame_width;		// Width of a single frame
	size_t			frame_height;		// Height of a single frame
	size_t			padding_x;			// Number of pixels arround each frame on the x axis
	size_t			padding_y;			// Number of pixels arround each frame on the y axis
	size_t			start_frame;		// First frame index in the sprite sheet
	size_t			frame_count;		// Total number of frames in the animation
	size_t			current_frame;		// Current frame counter
	bool			mirrored;			// Indicates if the frame will be horizontally mirrored
	bool			bounce;				// Indicates if the animation should bounce (1 2 3 2 1 2 3 instead of 1 2 3 1 2 3)
	bool			playing_in_reverse;	// Indicates if the animation is playing backwards
	bool			needs_refresh;		// Indicates if the animation needs to be refreshed immediatly
	double			frame_duration_ms;	// Duration of a single frame in milliseconds
	double			elapsed_time_ms;	// Time that passed since the last frame in milliseconds
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
	bool			knight_status;
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

size_t		get_button_coords(t_menu_buttons button, t_coords_index xy);

void		update_animation(t_animation *a, double deltatime_s);
void		render_animation(t_animation a);
void		render_image(t_animation a, size_t src_x, size_t src_y);

mlx_texture_t	*texture_from_png(char *file_path);
mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path);
mlx_image_t	*new_image(mlx_t *mlx, size_t width, size_t height);
void		image_to_window(mlx_t *mlx, mlx_image_t *image, size_t x, size_t y);

void		clear_image(mlx_image_t *image);
uint32_t	get_pixel_value2(mlx_texture_t *img, size_t x, size_t y);

//maybe unecessary
uint32_t	get_pixel_value(mlx_image_t *img, size_t x, size_t y);
#endif
