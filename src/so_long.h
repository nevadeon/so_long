/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/17 16:19:53 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h> //malloc free open close exit
# include <unistd.h> //write read
# include <fcntl.h> //O_RDONLY
# include <string.h> //strerror
# include <stdio.h> //perror
# include "../libndav/libndav.h"

typedef enum e_error
{
	OK,
	NOT_RECTANGLE,
	UNEXPECTED_CHARACTER,
	WRONG_PLAYER_COUNT,
	WRONG_COLLECTIBLE_COUNT,
	WRONG_EXIT_COUNT,
	INCORRECT_MAP_WALLS
}	t_error;

typedef struct s_check
{
	size_t	nb_player;
	size_t	nb_collectible;
	size_t	nb_exit;
	size_t	map_width;
	size_t	map_hight;
}	t_check;

char	**get_map(char *file_name);
int		parse_map(char **map);
void	path_verifier(char **map);

size_t	ft_strclen2(const char *str, char c);
size_t	dim2_len(void **tab);
void	dim2_cpy(void **dest, void **src);
void	print_map(char **map);

#endif