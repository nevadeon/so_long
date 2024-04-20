/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 19:12:59 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_position	*pos_init(void)
{
	t_position	*pos;

	pos = (t_position *) malloc(sizeof(t_position));
	pos->error_x = -1;
	pos->error_y = -1;
	return (pos);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_position	*pos;

	if (verif_arg(argc, argv[1]))
		return (1);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map(DEFAULT_MAP_PATH);
	if (map == NULL)
		return (ft_putendl_fd(FAILED_TO_OPEN, STDERR_FILENO), ERR_OPEN);
	pos = pos_init();
	if (parse_map(map, pos) != OK)
	{
		print_map(map, pos);
		return (free_map(map), free(pos), 1);
	}
	return (free_map(map), free(pos), 0);
}
