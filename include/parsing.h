/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:22:49 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 22:54:20 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "so_long.h"

# define MASK 128

/*==============================================================================
                                    PARSING                                     
==============================================================================*/

/**
 * @brief Verify that user gave a correct map file name
 * 
 * @param argc The number of strings given to the program
 * @param filename The name of the text file that contains map data
 */
void	parse_arg(int argc, char *filename);

/**
 * @brief Launche all map test functions and return an error code if map is
 * invalid
 * 
 * @param map The map structure
 * @return 0 if map is valid and error_code otherwise
 */
t_error	parse_map(t_game_map *map);

/**
 * @brief In a nutshell, take advandate of the 8th unused bit of ascii chars to 
 * distinguish the parts of the map that are reachable and those that aren't. In
 *  detail, from the starting x and y of the player, use a recursive algorythm 
 * to go through the entire accessible part of the map. Everytime an untouched 
 * character is met, it is marqued with a binary MASK (that basically turns the 
 * char into a negative one). The function exit every time a wall (aka a '1') or 
 *  a marqued character (aka a negative char) is met.
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

#endif