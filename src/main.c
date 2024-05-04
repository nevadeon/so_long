/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/05 00:12:16 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_data	env;
	t_error		error_code;

	if (verif_arg(argc, argv[1]))
		return (EXIT_FAILURE);
	if (argc > 1)
		env.map = get_map(argv[1]);
	else
		env.map = get_map(DEFAULT_MAP_PATH);
	if (env.map == NULL)
		return (ft_putendl_fd(FAILED_TO_OPEN, STDERR_FILENO), ERR_OPEN);
	error_code = parse_map(&env);
	if (error_code != OK)
	{
		if (error_code != ERR_MAP_SIZE)
			print_map(env.map);
		return (free_map(env.map), error_code);
	}
	if (game())
		return (free_map(env.map), EXIT_FAILURE);
	return (free_map(env.map), EXIT_SUCCESS);
}
