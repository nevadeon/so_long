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
# define PATH_STEAK			"assets/Deco/03.png"
# define PATH_EXIT			"assets/Deco/06.png"

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
}	t_player_data;

/**
 * @brief Contains all date used to render an animation.
 *
 * @param sprite_sheet The texture containing all frames of the animation.
 * @param render_layer The image that is displayed on the screen.
 * @param dest_x The X position in the render image where the animation will be
 * drawn.
 * @param dest_y The Y position in the render image where the animation will be
 * drawn.
 * @param frame_width The width of a single frame in the sprite sheet.
 * @param frame_height The height of a single frame in the sprite sheet.
 * @param padding_x The number of pixels around each frame on the X axis.
 * @param padding_y The number of pixels around each frame on the Y axis.
 * @param start_frame The index of the first frame in the sprite sheet.
 * @param frame_count The total number of frames in the animation.
 * @param current_frame The current frame being displayed in the animation.
 * @param is_mirrored A boolean indicating whether the frame should be horizontally
 * is_mirrored.
 * @param is_bounce_anim A boolean that determines if the animation should is_bounce_anim (i.e.,
 * play in a 1 2 3 2 1 loop).
 * @param is_playing_in_reverse A boolean indicating whether the animation is
 * playing backwards (in reverse order).
 * @param needs_clear_refresh A boolean indicating if the animation needs to
 * be reseted and refreshed immediately (used for fast updates).
 * @param frame_duration_ms The duration in milliseconds that each frame should
 * be displayed.
 * @param elapsed_time_ms The elapsed time in milliseconds since the last frame
 * change.
 */
typedef struct s_animation
{
	mlx_texture_t	*sprite_sheet;
	mlx_image_t		*render_layer;
	double			frame_duration_ms;
	double			elapsed_time_ms;
	uint16_t		dest_x;
	uint16_t		dest_y;
	uint16_t		frame_width;
	uint16_t		frame_height;
	uint16_t		padding_x;
	uint16_t		padding_y;
	uint16_t		start_frame;
	uint16_t		frame_count;
	uint16_t		current_frame;
	bool			is_mirrored;
	bool			is_bounce_anim;
	bool			is_playing_in_reverse;
	bool			needs_clear_refresh;
}	t_animation;

typedef struct s_game_map
{
	char		**grid;
	int32_t		player_pos_x;
	int32_t		player_pos_y;
	uint32_t	player_index_x;
	uint32_t	player_index_y;
	uint32_t	width;
	uint32_t	height;
	uint32_t	nb_collectibles;
	uint32_t	move_counter;
}	t_game_map;

typedef struct s_game_env
{
	mlx_t			*mlx;
	mlx_image_t		*foreground;
	mlx_image_t		*start_bt;
	mlx_image_t		*exit_bt;
	mlx_image_t		*water;
	mlx_image_t		*sand;
	mlx_image_t		*exit;
	mlx_image_t		*steak;
	t_animation		menu_bg_anim;
	t_animation		select_anim;
	t_animation		idle_knight;
	t_animation		moving_knight;
	t_game_map		map;
	t_game_status	game_status;
	t_menu_buttons	selected_button;
	t_player_data	player;
}	t_game_env;

#endif
