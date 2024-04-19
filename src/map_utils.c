/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:36:19 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/19 18:31:07 by ndavenne         ###   ########.fr       */
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

void	print_map(char **map, t_position *pos)
{
	size_t	map_hight;
	size_t	y;
	size_t	x;

	map_hight = dim2_len((void **) map);
	y = -1;
	while (++y < map_hight)
	{
		if (y == pos->error_y)
		{
			x = -1;
			while (map[y][++x] != '\0')
			{
				if (x == pos->error_x)
					ft_printf("\033[38;2;255;0;5;5m%c\033[0m", map[y][x]);
				else
					ft_printf("%c", map[y][x]);
			}
		}
		else
			ft_printf("%s", map[y]);
		ft_printf("\n");
	}
}
