/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/17 16:37:51 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map		map;
	t_game_visuals	gv;
	t_game_env		env;

	parse_inputs(argc, argv, &map);
	so_long(&map, &gv, &env);
	// free_graphics(&gv);
	free_map(map.grid);
	return (EXIT_SUCCESS);
}
