/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:36:19 by ndavenne          #+#    #+#             */
/*   Updated: 2024/04/16 16:38:41 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		ft_printf("%s", map[i]);
		i++;
	}
}
