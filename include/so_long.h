/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/05 00:00:56 by nevadeon         ###   ########.fr       */
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
# include "libndav.h"
# include "MLX42.h"

# define DEFAULT_MAP_PATH "maps/default.ber"
# define MASK 128

/*error messages*/
# define TOO_MANY_ARGS "Error\ntoo many arguments\n"
# define SHORT_FILE_NAME "Error\nfile name too short\n"
# define WRONG_FILE_EXT "Error\nincorrect file extension\n"
# define EMPTY_MAP "Error\nEmpty map"
# define FAILED_TO_OPEN "Error\nFound no corresponding file"
# define MAP_TOO_BIG "Error\nMap is too big"
# define NOT_RECTANGLE "Error\nMap is not a rectangle\n"
# define UNEXPECTED_CHARACTER "Error\nMap contains unexpected character\n"
# define WRONG_MAP_WALLS "Error\nOpening in exterior walls\n"
# define WRONG_PLAYER_COUNT "Error\nMap must have exactly 1 player\n"
# define WRONG_EXIT_COUNT "Error\nMap must have exactly 1 exit\n"
# define WRONG_COLLECTIBLE_COUNT "Error\nMap must have at least 1 collectible\n"
# define UNREACHABLE_OBJ "Error\nUnreachable exit or collectible\n"

/*error colors*/
# define COLOR_UNREACH "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
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
	ERR_RECT,
	ERR_MAP_SIZE,
	ERR_CHAR,
	ERR_WALL,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COL,
	ERR_UNREACH,
	ERR_FRAME_DIMENSION
}	t_error;

typedef struct s_game_data
{
	char	**map;
	size_t	map_width;
	size_t	map_height;
	t_uint	player_x;
	t_uint	player_y;
}	t_game_data;

/*map*/
char	**get_map(char *file_name);
void	print_map(char **map);
void	free_map(char **map);

/*map utils*/
size_t	ft_strclen2(const char *str, char c);
size_t	dim2_len(void **tab);
void	dim2_cpy(void **dest, void **src);

/*parsing*/
t_error	verif_arg(int argc, char *filename);
t_error	parse_map(t_game_data *env);
t_error	check_map_size(t_game_data *env);
t_error	is_rectangle(char **map, size_t map_width);
t_error	check_outer_walls(char **map, size_t map_width, size_t map_height);
t_error	check_characters(char **map);
t_error	count_collectible(char **map);
t_error	count_player(char **map);
t_error	count_exit(char **map);
t_error	search_unreachable(char **map);
void	reset_map(char **map);

/*game*/
int		game(void);

#endif