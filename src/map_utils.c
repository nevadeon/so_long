/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:36:19 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/18 21:14:20 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strclen2(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

size_t	dim2_len(void **tab)
{
	size_t	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

void	dim2_cpy(void **dest, void **src)
{
	while (*src != NULL)
		*dest++ = *src++;
	*dest = NULL;
}

void	print_map(char **map)
{
	size_t	i;

	i = 0;
	while (i < dim2_len((void **) map))
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\n");
}

void	get_player_position(char **map, t_position *pos)
{
	size_t	i;
	size_t	j;

	j = -1;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\0')
		{
			if (map[j][i] == 'P')
			{
				pos->player_x = i;
				pos->player_y = j;
			}
		}
	}
}
