/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 19:14:21 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> //malloc free open close exit
# include <unistd.h> //write read
# include <fcntl.h> //O_RDONLY
# include <string.h> //strerror
# include <stdio.h> //perror
# include "../libndav/headers/libndav.h"

# define DEFAULT_MAP_PATH "../maps/default.ber"

/*error section*/
# define TOO_MANY_ARGS "Error\ntoo many arguments\n"
# define SHORT_FILE_NAME "Error\nfile name too short\n"
# define WRONG_FILE_EXT "Error\nincorrect file extension\n"
# define EMPTY_MAP "Error\nEmpty map"
# define FAILED_TO_OPEN "Error\nfile opening failure"
# define MAP_TOO_BIG "Error\nMap is too big"
# define NOT_RECTANGLE "Error\nMap is not a rectangle\n"
# define UNEXPECTED_CHARACTER "Error\nMap contains an unexpected character\n"
# define WRONG_MAP_WALLS "Error\nBreach in exterior walls\n"
# define WRONG_PLAYER_COUNT "Error\nMap must have exactly 1 player\n"
# define WRONG_EXIT_COUNT "Error\nMap must have exactly 1 exit\n"
# define WRONG_COLLECTIBLE_COUNT "Error\nMap must have at least 1 collectible\n"
# define UNREACHABLE_OBJ "Error\nUnreachable exit or collectible\n"

typedef enum e_error
{
	OK,
	ERR_ARGS,
	ERR_NAME,
	ERR_EXT,
	ERR_OPEN,
	ERR_EMPTY,
	ERR_RECT,
	ERR_MAP_SIZE,
	ERR_CHAR,
	ERR_WALL,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COL,
	ERR_UNREACH
}	t_error;

typedef struct s_position
{
	size_t	player_x;
	size_t	player_y;
	ssize_t	error_x;
	ssize_t	error_y;
}	t_position;

char	**get_map(char *file_name);
void	free_map(char **map);

/*map utils*/
size_t	ft_strclen2(const char *str, char c);
size_t	dim2_len(void **tab);
void	dim2_cpy(void **dest, void **src);
void	print_map(char **map, t_position *pos);

/*parsing*/
t_error	verif_arg(int argc, char *filename);
t_error	parse_map(char **map, t_position *pos);
t_error	is_rectangle(char **map, t_position *pos);
t_error	check_map_size(char **map);
t_error	check_characters(char **map, t_position *pos);
t_error	check_outer_walls(char **map, t_position *pos);
t_error	count_collectible(char **map, t_position *pos);
t_error	count_player(char **map, t_position *pos);
t_error	count_exit(char **map, t_position *pos);
void	reset_map(char **map);

#endif