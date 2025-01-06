/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 10:52:00 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"

# define MASK 128
# define DEFAULT_MAP_PATH "maps/default.ber"

/*------------------------------------------------------------------------------
                               map printing colors
------------------------------------------------------------------------------*/

# define COLOR_ERROR "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
# define COLOR_GROUND "\033[48;2;87;213;199m\033[30m%c\033[0m"
# define COLOR_PCE "\033[48;2;173;226;93m\033[30m%c\033[0m"
# define COLOR_WALL "\033[48;2;108;169;189m\033[30m%c\033[0m"

typedef struct s_game_map
{
	char	**grid;
	size_t	width;
	size_t	height;
	size_t	player_x;
	size_t	player_y;
}	t_game_map;

/*==============================================================================
                                    PARSING
==============================================================================*/

void	parse_args(int argc, char *argv[], t_game_map *map);

/**
 * @brief Launch all map test functions and return an error code if map is
 * invalid
 *
 * @param map The map structure
 * @return 0 if map is valid and error_code otherwise
 */
t_error	parse_map(t_game_map *map);

/**
 * @brief In a nutshell, takes advandate of the 8th unused bit of ascii chars to
 * distinguish the parts of the map that are reachable and those that aren't. In
 * detail, from the starting x and y of the player, use a recursive algorythm
 * to go through the entire accessible part of the map. Everytime an untouched
 * character is met, it is marqued with a binary MASK (that basically turns the
 * char into a negative one). The function exit every time a wall (aka a '1') or
 *  a marqued character (aka a negative char) is met.
 *
 * @param map The map data
 * @param x The collumn of the current character
 * @param y The raw of the current character
 */
void	mark_reachable_items(char **grid, size_t x, size_t y);

/*------------------------------------------------------------------------------
                                   map tests
------------------------------------------------------------------------------*/

t_error	check_map_size(t_game_map *map);
t_error	is_rectangle(char **grid, size_t map_width);
t_error	check_outer_walls(char **grid, size_t map_width, size_t map_height);
t_error	check_characters(char **grid);
t_error	count_collectible(char **grid);
t_error	count_player(char **grid);
t_error	count_exit(char **grid);
t_error	check_unreachable(char **grid);

/*==============================================================================
                                   MAP TOOLS
==============================================================================*/

/**
 * @brief Put each line of a text file in an array of strings
 *
 * @param file_name The text file that contains map data
 * @return A mallocated 2 dimensions array of strings
 */
char	**get_map(char *file_name);

/**
 * @brief Free all mallocs from get_map function
 *
 * @param map The array of strings
 */
void	free_map(char **grid);

/**
 * @brief Cycle through an array of strings and reverse a previously applied
 * binary MASK
 *
 * @param map The array of strings
 */
void	reset_map(char **grid);

/**
 * @brief Prints map data into terminal with colors
 *
 * @param map The array of strings
 */
void	print_map(char **map);

/**
 * @brief Gets the player position and stores it in map structure player_x and
 * player_y variables
 *
 * @param map The map structure
 */
void	get_player_position(t_game_map *map);

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
char	**_dim2join_free(char **tab, char *str);

/**
 * @brief Calculate the size of a NULL terminated 2 dimensions array
 *
 * @param tab The 2 dimensions NULL terminated array
 * @return The lenght of the array
 */
size_t	dim2_len(void **tab);

/**
 * @brief Copy a NULL terminated 2 dimensions array into another one
 * and NULL terminate the destination
 *
 * @param dest The destination array
 * @param src The source array
 */
void	dim2_cpy(void **dest, void **src);

#endif
