#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>	//malloc free open close exit
# include <unistd.h>	//write read
# include <fcntl.h>		//O_RDONLY
# include <string.h>	//strerror
# include <stdio.h>		//perror
# include <stdbool.h>	//bool true false
# include "MLX42.h"		//graphic lib
# include "libndav.h"
# ifdef INCLUDE_TEST_HEADER
#  include "test.h"
# endif

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
# define DEFAULT_MAP_PATH	"maps/valid_1.ber"

/*------------------------------------------------------------------------------
                               map printing colors
------------------------------------------------------------------------------*/

# define COLOR_ERROR "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
# define COLOR_GROUND "\033[48;2;87;213;199m\033[30m%c\033[0m"
# define COLOR_PCE "\033[48;2;173;226;93m\033[30m%c\033[0m"
# define COLOR_WALL "\033[48;2;108;169;189m\033[30m%c\033[0m"

/**
 * @brief Error codes that are used to identify corresponding error message and
 * are also used as exit program value
 */
typedef enum e_error
{
	OK = 0,
	ERR_ARGS,
	ERR_NAME,
	ERR_OPEN,
	ERR_EMPTY_MAP,
	ERR_MAP_SIZE,
	ERR_RECT,
	ERR_WALL,
	ERR_CHAR,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COL,
	ERR_UNREACH,
	ERR_BUTTON_INDEX,
	ERR_RENDER_INDEX,
	ERR_ARGV,
	ERR_MAX_INDEX
}	t_error;

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

typedef enum e_anim_type
{
	CLASSIC,
	BOUNCE_PLAYING_FORWARD,
	BOUNCE_PLAYING_BACKWARD
}	t_anim_type;

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
 * @param anim_type An enum that determines if the animation should play in a
 * classic way (i.e. play in a 1 2 3 1 2 3 loop)
 * or bounce (i.e. play in a 1 2 3 2 1 loop).
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
	uint32_t		dest_x;
	uint32_t		dest_y;
	uint32_t		frame_width;
	uint32_t		frame_height;
	uint32_t		padding_x;
	uint32_t		padding_y;
	uint32_t		start_frame;
	uint32_t		frame_count;
	uint32_t		current_frame;
	t_anim_type		anim_type;
	bool			is_mirrored;
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

void		start_game(t_game_env *env);
void		exit_game(t_game_env *env);

//hooks
void		key_hook(mlx_key_data_t keydata, void *param);
void		update_game(void *param);
void		update_positions(t_game_env *env);

void		init_graphics(t_game_env *env, t_game_map map);

uint32_t	get_button_coords(t_menu_buttons button, t_coords_index xy);
void		update_animation(t_animation *a, double deltatime_s);
void		clear_image(mlx_image_t *image);
uint32_t	get_pixel_value(mlx_texture_t *img, uint32_t x, uint32_t y);

//mlx wrappers
typedef mlx_texture_t	t_texture;
t_texture	*texture_from_png(char *file_path);
mlx_image_t	*image_from_png(mlx_t	*mlx, char *file_path);
mlx_image_t	*new_image(mlx_t *mlx, uint32_t width, uint32_t height);
int32_t		image_to_window(\
						mlx_t *mlx, mlx_image_t *image, uint32_t x, uint32_t y);

/*==============================================================================
                                    PARSING
==============================================================================*/

t_game_map	process_args(int argc, char *argv[]);

/**
 * @brief Launch all map test functions and return an error code if map is
 * invalid
 *
 * @param map The map structure
 * @return 0 if map is valid and error_code otherwise
 */
t_error		parse_map(t_game_map *map);

/**
 * @brief In a nutshell, takes advandate of the 8th unused bit of ascii chars to
 * distinguish the parts of the map that are reachable and those that aren't. In
 * detail, from the starting x and y of the player, use a recursive algorythm
 * to go through the entire accessible part of the map. Everytime an untouched
 * character is met, it is marqued with a binary 1 << 7 (that basically turns the
 * char into a negative one). The function exit every time a wall (aka a '1') or
 *  a marqued character (aka a negative char) is met.
 *
 * @param map The map data
 * @param x The collumn of the current character
 * @param y The raw of the current character
 */
void		_mark_reachable_items(char **grid, uint32_t x, uint32_t y);

/*------------------------------------------------------------------------------
                                   map tests
------------------------------------------------------------------------------*/

t_error		check_map_size(t_game_map *map);
t_error		is_rectangle(char **grid, uint32_t width);
t_error		check_outer_walls(char **grid, uint32_t width, uint32_t height);
t_error		count_collectible(char **grid, uint32_t *nb);
t_error		check_characters(char **grid);
t_error		count_player(char **grid);
t_error		count_exit(char **grid);
t_error		check_unreachable(char **grid);

/*==============================================================================
                                   MAP TOOLS
==============================================================================*/

/**
 * @brief Put each line of a text file in an array of strings
 *
 * @param file_name The text file that contains map data
 * @return A mallocated 2 dimensions array of strings
 */
char		**get_map(char *file_name);

/**
 * @brief Free all mallocs from get_map function
 *
 * @param map The array of strings
 */
void		free_map(char **grid);

/**
 * @brief Cycle through an array of strings and reverse a previously applied
 * binary 1 << 7
 *
 * @param map The array of strings
 */
void		reset_map(char **grid);

/**
 * @brief Prints map data into terminal with colors
 *
 * @param map The array of strings
 */
void		print_map(char **map);

/**
 * @brief Gets the player position and stores it in map structure player_x and
 * player_y variables
 *
 * @param map The map structure
 */
void		get_player_position(t_game_map *map);

/*------------------------------------------------------------------------------
                                   map utils
------------------------------------------------------------------------------*/

/**
 * @brief Copy an array of strings in a new mallocated array. Add a string at
 * the end of the copy array and free the source array
 *
 * @param tab The array to be copied and freed
 * @param str The string that will be added at the end of the copy
 * @return The newly constructed array
 */
char		**_dim2join_free(char **tab, char *str);

/**
 * @brief Calculate the size of a NULL terminated 2 dimensions array
 *
 * @param tab The 2 dimensions NULL terminated array
 * @return The lenght of the array
 */
uint32_t	dim2_len(void **tab);

/**
 * @brief Copy a NULL terminated 2 dimensions array into another one
 * and NULL terminate the destination
 *
 * @param dest The destination array
 * @param src The source array
 */
void		dim2_cpy(void **dest, void **src);

/*==============================================================================
                                ERROR MANAGEMENT
==============================================================================*/

/**
 * @brief Take an error code and look in the error_message table for the
 * correspongind message
 *
 * @param error_code The error code
 * @return The corresponding error message
 */
const char	*get_error_message(t_error error_code);

/**
 * @brief Put an error mesage in the standard error file descriptor and exit
 * the program
 *
 * @param error_code The error code
 */
void		error(t_error error_code);

/**
 * @brief Print the global error variable of the mlx library and exit
 * the program
 */
void		handle_mlx_error(void);

#endif
