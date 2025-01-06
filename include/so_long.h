/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@glhf.slmail.me>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:22:48 by ndavenne          #+#    #+#             */
/*   Updated: 2025/01/06 12:03:55 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>	//malloc free open close exit
# include <unistd.h>	//write read
# include <fcntl.h>		//O_RDONLY
# include <string.h>	//strerror
# include <stdio.h>		//perror
# include <stdbool.h>	//bool true false

# include "MLX42.h"		//graphic lib
# include "libndav.h"
# include "errors.h"
# include "map.h"
# include "graphics.h"

typedef struct s_game_env
{

}	t_game_env;
// void	init_game(t_game_env *env);

#endif
