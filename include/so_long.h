/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:53:03 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/07 13:38:24 by ndavenne         ###   ########.fr       */
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
# include "parsing.h"
# include "graphics.h"
# include "errors.h"
# include "map.h"

/*==============================================================================
                               WORK IN PROGRESS                                 
==============================================================================*/

void	so_long(t_game_map *map, t_game_visuals *graphs);
size_t	ft_strclen2(const char *str, char c);

#endif