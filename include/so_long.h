/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:22:48 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/17 16:34:39 by ndavenne         ###   ########.fr       */
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

typedef enum e_game_status
{
	IN_MENU,
	PLAYING
}	t_game_status;

typedef enum e_menu_selection
{
	SELECT_START,
	SELECT_EXIT,
	SELECT_MAX
}	t_menu_selection;

typedef struct s_game_env
{
	t_game_status		game_status;
	t_menu_selection	menu_selection;
}	t_game_env;

void	so_long(t_game_map *map, t_game_visuals *gv, t_game_env *env);

#endif