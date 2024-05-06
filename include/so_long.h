/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 20:59:18 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>  //malloc free open close exit
# include <unistd.h>  //write read
# include <fcntl.h>   //O_RDONLY
# include <string.h>  //strerror
# include <stdio.h>   //perror
# include <stdbool.h> //bool true false
# include "MLX42.h"   //graphic lib
# include "libndav.h"
# include "graphics.h"

# define DEFAULT_MAP_PATH "maps/default.ber"
# define MASK 128

/*map printing colors*/
# define COLOR_ERROR "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
# define COLOR_GROUND "\033[48;2;87;213;199m\033[30m%c\033[0m"
# define COLOR_PCE "\033[48;2;173;226;93m\033[30m%c\033[0m"
# define COLOR_WALL "\033[48;2;108;169;189m\033[30m%c\033[0m"

typedef enum e_error
{
	OK = 0,
	ERR_ARGS,
	ERR_NAME,
	ERR_EXT,
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
	ERR_FRAME_DIMENSION,
	ERR_MAX
}	t_error;

typedef struct s_game_map
{
	char		**grid;
	size_t		width;
	size_t		height;
	uint32_t	player_x;
	uint32_t	player_y;
}	t_game_map;

/*==============================================================================
                                   MAP TOOLS                                    
==============================================================================*/

/**
 * @brief Puts each line of a text file in an array of strings
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
void	free_map(char **map);

/**
 * @brief Cycle through an array of strings and reverse a previously applied
 * binary MASK
 * 
 * @param map The array of strings
 */
void	reset_map(char **map);

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
 * @brief Copies an array of strings in a new mallocated array. Adds a string at
 * the end of the copy array and frees the source array
 * 
 * @param tab The array to be copied and freed
 * @param str The string that will be added at the end of the copy
 * @return The newly constructed array
 */
char	**_dim2join_free(char **tab, char *str);

/**
 * @brief Calculates the size of a NULL terminated 2 dimensions array
 * 
 * @param tab The 2 dimensions NULL terminated array
 * @return The lenght of the array
 */
size_t	dim2_len(void **tab);

/**
 * @brief Copies a NULL terminated 2 dimensions array into another one
 * and NULL terminates the destination
 * 
 * @param dest The destination array
 * @param src The source array
 */
void	dim2_cpy(void **dest, void **src);

/*==============================================================================
                                    PARSING                                     
==============================================================================*/

/**
 * @brief Verify that user gave a correct map file
 * 
 * @param argc The number of strings given to the programm
 * @param filename The name of the text file that contains map data
 */
void	parse_arg(int argc, char *filename);

/**
 * @brief Launches all map test functions and returns an error code if map is
 * invalid
 * 
 * @param map The map structure
 * @return 0 if map is valid and error_code otherwise
 */
t_error	parse_map(t_game_map *map);

/**
 * @brief In a nutshell, this function takes advandate of the 8th unused bit of 
 * ascii chars to distinguish the parts of the map that are reachable and those 
 * that aren't. In detail, from the starting x and y of the player, the function
 *  uses a recursive algorythm to go through the entire accessible part of the
 * map. Everytime the function meets an untouched character, it marks it with 
 * a binary MASK (that basically turns the char into a negative one). The 
 * function exit every time it meets a wall (aka a '1') or a marqued character 
 * (aka a negative char).
 * 
 * @param map The map data
 * @param x The collumn of the current character
 * @param y The raw of the current character
 */
void	parse_path(char **map, uint32_t x, uint32_t y);

/*------------------------------------------------------------------------------
                                   map tests                                    
------------------------------------------------------------------------------*/

t_error	check_map_size(t_game_map *map);
t_error	is_rectangle(char **map, size_t map_width);
t_error	check_outer_walls(char **map, size_t map_width, size_t map_height);
t_error	check_characters(char **map);
t_error	count_collectible(char **map);
t_error	count_player(char **map);
t_error	count_exit(char **map);
t_error	search_unreachable(char **map);

/*==============================================================================
                                ERROR MANAGEMENT                                
==============================================================================*/

/**
 * @brief Takes an error code and look in the error_message table for the 
 * correspongind message
 * 
 * @param error_code The error code
 * @return The corresponding error message
 */
char	*get_error_message(t_error error_code);

/**
 * @brief Puts an error mesage in the standard error file descriptor and exit
 * the program
 * 
 * @param error_code The error code
 */
void	error(t_error error_code);

/**
 * @brief Prints the global error variable of the mlx library and exit
 * the program
 */
void	mlx_error(void);

/*==============================================================================
                               WORK IN PROGRESS                                 
==============================================================================*/

void	so_long(t_game_map *map, t_game_visuals *graph);
size_t	ft_strclen2(const char *str, char c);

#endif