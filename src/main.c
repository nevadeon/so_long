/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/22 00:29:10 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char			**map;
	t_environment	*env;

	if (verif_arg(argc, argv[1]))
		return (1);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map(DEFAULT_MAP_PATH);
	if (map == NULL)
		return (ft_putendl_fd(FAILED_TO_OPEN, STDERR_FILENO), ERR_OPEN);
	env = (t_environment *) malloc(sizeof(t_environment));
	if (parse_map(map, env) != OK)
	{
		print_map(map);
		return (free_map(map), free(env), 1);
	}
	return (free_map(map), free(env), 0);
}
