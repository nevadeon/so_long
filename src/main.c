/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <nevadeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/21 13:19:19 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_position(char **map, t_environment *env)
{
	size_t	y;
	size_t	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] == 'P')
			{
				env->player_x = x;
				env->player_y = y;
			}
		}
	}
}

t_environment	*env_init(char **map)
{
	t_environment	*env;

	env = (t_environment *) malloc(sizeof(t_environment));
	get_player_position(map, env);
	env->map_width = ft_strlen(map[0]);
	env->map_hight = dim2_len((void **) map);
	return (env);
}

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
	env = env_init(map);
	if (parse_map(map, env) != OK)
	{
		print_map(map);
		return (free_map(map), free(env), 1);
	}
	return (free_map(map), free(env), 0);
}
