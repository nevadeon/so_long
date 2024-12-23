/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:44:11 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/23 09:15:18 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*get_error_message(t_error error_code)
{
	static const char	*message[] = {
		"Error\nHow the hell did you get this error message ?",
		"Error\ntoo many arguments",
		"Error\nfile name too short",
		"Error\nincorrect file extension",
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
		"Error\nThe dev is a fucking morron",
		"Error\nIndex is out of <char *error_message[]> boundaries",
	};

	if (error_code < 0 || error_code > ERR_MAX)
		return (message[ERR_MAX]);
	return (message[error_code]);
}

void	error(t_error error_code)
{
	ft_dputendl(STDERR_FILENO, get_error_message(error_code));
	exit(error_code);
}

void	handle_mlx_error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
