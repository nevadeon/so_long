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

t_error	verif_arg(int argc, char *filename)
{
	size_t	len;

	if (argc > 2)
		return (ft_putendl_fd(TOO_MANY_ARGS, STDERR_FILENO), ERR_ARGS);
	if (argc == 2)
	{
		len = ft_strlen(filename);
		if (len < 5)
			return (ft_putendl_fd(SHORT_FILE_NAME, STDERR_FILENO), ERR_NAME);
		if (memcmp(filename + len - 4, ".ber", 4))
			return (ft_putendl_fd(WRONG_FILE_EXT, STDERR_FILENO), ERR_EXT);
	}
	return (OK);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_position	*pos;
	t_error		error_code;

	if (verif_arg(argc, argv[1]))
		return (1);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map(DEFAULT_MAP_PATH);
	pos = (t_position *) malloc(sizeof(t_position));
	error_code = parse_map(map, pos);
	reset_map(map);
	if (error_code != OK)
	{
		if (error_code != ERR_OPEN && error_code != ERR_MAP_SIZE)
			print_map(map, pos);
		return (free(pos), 1);
	}
	return (free(pos), 0);
}
