/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/25 14:48:30 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;
	t_envir	*env;
	t_error	error_code;

	if (verif_arg(argc, argv[1]))
		return (EXIT_FAILURE);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map(DEFAULT_MAP_PATH);
	if (map == NULL)
		return (ft_putendl_fd(FAILED_TO_OPEN, STDERR_FILENO), ERR_OPEN);
	env = (t_envir *) malloc(sizeof(t_envir));
	error_code = parse_map(map, env);
	if (error_code != OK)
	{
		if (error_code != ERR_MAP_SIZE)
			print_map(map);
		return (free_map(map), free(env), EXIT_FAILURE);
	}
	if (intro())
		return (free_map(map), free(env), EXIT_FAILURE);
	if (game(env))
		return (free_map(map), free(env), EXIT_FAILURE);
	return (free_map(map), free(env), EXIT_SUCCESS);
}
