/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:36:19 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/10 00:42:36 by nevadeon         ###   ########.fr       */
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
