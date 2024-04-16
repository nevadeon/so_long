/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:50:05 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/16 16:39:56 by ndavenne         ###   ########.fr       */
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
	char	**map;

	if (_verif_arg(argc, argv[1]))
		return (1);
	if (argc == 1)
		map = get_map("../maps/default.ber");
	else
		map = get_map(argv[1]);
	print_map(map);
	return (0);
}
