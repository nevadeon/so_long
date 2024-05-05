/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:54:14 by nevadeon          #+#    #+#             */
/*   Updated: 2024/05/05 14:34:08 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*error_message[] = {
	"Error\nHow the hell did you get this error message ?",
	"Error\ntoo many arguments\n",
	"Error\nfile name too short\n",
	"Error\nincorrect file extension\n",
	"Error\nFound no corresponding file",
	"Error\nEmpty map",
	"Error\nMap is too big",
	"Error\nMap is not a rectangle\n",
	"Error\nOpening in exterior walls\n",
	"Error\nMap contains an unexpected character\n",
	"Error\nMap must have exactly 1 player\n",
	"Error\nMap must have exactly 1 exit\n",
	"Error\nMap must have at least 1 collectible\n",
	"Error\nUnreachable exit or collectible\n",
	"Error\nWTF ? Specified sprite frame dimension is incorrect\n",
	"Error\nIndex is out of <char *error_message[]> boundaries\n",
};

char	*get_error_message(t_error error_code)
{
	if (error_code < 0 || error_code > ERR_MAX)
		error(ERR_MAX);
	return (error_message[error_code]);
}

/*turns all negative characters back to their original value*/
void	reset_map(char **map)
{
	t_uint	x;
	t_uint	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x] != '\0')
		{
			if (map[y][x] & MASK)
				map[y][x] ^= MASK;
		}
	}
}
