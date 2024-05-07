/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:31:00 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/07 14:25:22 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "so_long.h"
# include "MLX42.h"   //graphic lib
# include "libndav.h"
# include "parsing.h"
# include "graphics.h"
# include "errors.h"
# include "map.h"

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