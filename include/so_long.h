#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>	//malloc free open close exit
# include <unistd.h>	//write read
# include <fcntl.h>		//O_RDONLY
# include <string.h>	//strerror
# include <stdio.h>		//perror
# include <stdbool.h>	//bool true false

# include "MLX42.h"		//graphic lib
# include "definitions.h"
# include "libndav.h"
# include "errors.h"
# include "map.h"
# include "graphics.h"

void	start_game(t_game_env *env);
void	exit_game(t_game_env *env);

//hooks
void	key_hook(mlx_key_data_t keydata, void *param);
void	update_game(void *param);
void	update_positions(t_game_env *env);

#endif
