/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/16 16:40:34 by ndavenne         ###   ########.fr       */
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

typedef struct s_game
{
	size_t	map_width;
	size_t	map_hight;
	size_t	nb_exit;
	size_t	nb_player;
	size_t	nb_collectible;
}	t_game;

char	**get_map(char *file_name);
size_t	dim2_len(void **tab);
void	dim2_cpy(void **dest, void **src);
void	print_map(char **map);

#endif