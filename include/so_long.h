/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 17:02:08 by ndavenne         ###   ########.fr       */
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

# define DEFAULT_MAP_PATH "maps/default.ber"
# define MASK 128

/*error colors*/
# define COLOR_ERROR "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
# define COLOR_GROUND "\033[48;2;87;213;199m\033[30m%c\033[0m"
# define COLOR_PCE "\033[48;2;173;226;93m\033[30m%c\033[0m"
# define COLOR_WALL "\033[48;2;108;169;189m\033[30m%c\033[0m"

typedef unsigned int uint32_t;

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

/*map*/
char	**get_map(char *file_name);
void	free_map(char **map);
void	reset_map(char **map);
void	print_map(char **map);
void	get_player_position(t_game_map *map);

/*map utils*/
size_t	ft_strclen2(const char *str, char c);
size_t	dim2_len(void **tab);
void	dim2_cpy(void **dest, void **src);

/*parsing*/
t_error	parse_map(t_game_map *map);
t_error	check_map_size(t_game_map *map);
t_error	is_rectangle(char **map, size_t map_width);
t_error	check_outer_walls(char **map, size_t map_width, size_t map_height);
t_error	check_characters(char **map);
t_error	count_collectible(char **map);
t_error	count_player(char **map);
t_error	count_exit(char **map);
t_error	search_unreachable(char **map);

/*game*/
void	so_long(t_game_map *map, t_game_visuals *graph);

/*error*/
void	error(t_error error_code);

#endif