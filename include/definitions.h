#ifndef DEFINITIONS_H
# define DEFINITIONS_H

# include "so_long.h"

# define WINDOW_TITLE "so_long"
# define WIDTH	1309
# define HEIGHT	995
# define TILE_SIZE 64

# define PATH_MENU_BG		"assets/UI/Menu/Menu_background.png"
# define PATH_SELECT		"assets/UI/Menu/Select_sprite.png"
# define PATH_START_BUTTON	"assets/UI/Menu/Start.png"
# define PATH_EXIT_BUTTON	"assets/UI/Menu/Exit.png"
# define PATH_BLUE_KNIGHT	"assets/Factions/Knights/Warrior/Warrior_Blue.png"
# define PATH_WATER			"assets/Terrain/Water/Water.png"
# define PATH_SAND			"assets/Terrain/Ground/Sand.png"

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

typedef enum e_menu_buttons
{
	BTN_START,
	BTN_EXIT,
	BTN_MAX
}	t_menu_buttons;

typedef struct s_player_data
{
	bool	is_left;
	bool	is_right;
	bool	is_up;
	bool	is_down;
	bool	is_moving;
	bool	was_moving;
} t_player_data;

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

typedef struct s_game_map
{
	char		**grid;
	mlx_image_t	**tiles;
	size_t		width;
	size_t		height;
	size_t		player_x;
	size_t		player_y;
	long		player_pos_x;
	long		player_pos_y;
	size_t		nb_collectibles;
}	t_game_map;

typedef struct s_game_env
{
	t_player_data	player;
	mlx_t			*mlx;
	mlx_image_t		*foreground;
	mlx_image_t		*start_bt;
	mlx_image_t		*exit_bt;
	mlx_image_t		*water;
	mlx_image_t		*sand;
	t_animation		menu_bg_anim;
	t_animation		select_anim;
	t_animation		idle_knight;
	t_animation		moving_knight;
	t_game_status	game_status;
	t_menu_buttons	selected_button;
	t_game_map		map;
}	t_game_env;

#endif
