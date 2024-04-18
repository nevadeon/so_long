/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/18 20:03:51 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_verif_arg(int argc, char *filename)
{
	size_t	len;

	if (argc > 2)
		return (ft_printf("Error\ntoo many arguments\n"));
	if (argc == 2)
	{
		len = ft_strlen(filename);
		if (len < 5)
			return (ft_printf("Error\nfile name too short\n"));
		if (memcmp(filename + len - 4, ".ber", 4))
			return (ft_printf("Error\nincorrect file extension\n"));
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char		**map;
	t_position	*pos;

	if (_verif_arg(argc, argv[1]))
		return (1);
	map = get_map(argv[1]);
	if (argc == 1)
		map = get_map("../maps/default.ber");
	if (map == NULL)
		return (ft_printf("Error\nError while opening the file"));
	if (map[0] == NULL)
		return (ft_printf("Error\nEmpty map\n"));
	pos = (t_position *) malloc(sizeof(t_position));
	print_map(map);
	if (parse_map(map, pos) != OK)
		return (1);
	free(pos);
	return (0);
}
