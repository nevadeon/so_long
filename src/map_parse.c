/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:42:46 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/17 16:18:07 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	struct_init(t_check *var, char **map)
{
	var->nb_player = 0;
	var->nb_collectible = 0;
	var->nb_exit = 0;
	var->map_width = ft_strlen(map[0]);
	var->map_hight = dim2_len((void **)map);
}

/*check that map is surrounded by '1'*/
t_error	check_exterior_walls(char **map, t_check *var)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if ((i == 0 || i == var->map_hight - 1
					|| j == 0 || j == var->map_width - 1)
				&& map[i][j] != '1')
				return (INCORRECT_MAP_WALLS);
		}
	}
	return (OK);
}

/*check if there is the correct number of players, collectible and exit
check if map is a rectangle and that all characters are P, C, E, 0 or 1*/
t_error	map_verifier(char **map, t_check *var)
{
	size_t	i;

	while (*map != NULL)
	{
		i = -1;
		while ((*map)[++i] != '\0')
		{
			if ((*map)[i] != 'P' && (*map)[i] != 'C' && (*map)[i] != 'E'
				&& (*map)[i] != '0' && (*map)[i] != '1')
				return (UNEXPECTED_CHARACTER);
			var->nb_player += ((*map)[i] == 'P');
			var->nb_collectible += ((*map)[i] == 'C');
			var->nb_exit += ((*map)[i] == 'E');
		}
		if (i != var->map_width)
			return (NOT_RECTANGLE);
		map++;
	}
	if (var->nb_player != 1)
		return (WRONG_PLAYER_COUNT);
	if (var->nb_collectible < 1)
		return (WRONG_COLLECTIBLE_COUNT);
	if (var->nb_exit != 1)
		return (WRONG_EXIT_COUNT);
	return (0);
}

/*prints and return an error message if map is invalid*/
int	parse_map(char **map)
{
	t_check	*variables;
	t_error	error_code;

	variables = (t_check *) malloc(sizeof(t_check));
	struct_init(variables, map);
	error_code = map_verifier(map, variables);
	if (error_code == NOT_RECTANGLE)
		return (ft_printf("Error\nmap is not a rectangle\n"));
	if (error_code == UNEXPECTED_CHARACTER)
		return (ft_printf("Error\nmap contains an unexpected character\n"));
	if (error_code == WRONG_PLAYER_COUNT)
		return (ft_printf("Error\nmap has an incorrect player count\n"));
	if (error_code == WRONG_COLLECTIBLE_COUNT)
		return (ft_printf("Error\nmap has an incorrect collectible count\n"));
	if (error_code == WRONG_EXIT_COUNT)
		return (ft_printf("Error\nmap has an incorrect exit count\n"));
	if (check_exterior_walls(map, variables) == INCORRECT_MAP_WALLS)
		return (ft_printf("Error\nmap exterior walls are not composed of 1\n"));
	free(variables);
	path_verifier(map);
	return (OK);
}
