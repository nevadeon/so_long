/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:28:12 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/06 22:56:53 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/*------------------------------------------------------------------------------
                               map printing colors                              
------------------------------------------------------------------------------*/

# define COLOR_ERROR "\033[48;2;222;107;72;5m\033[30m%c\033[0m"
# define COLOR_GROUND "\033[48;2;87;213;199m\033[30m%c\033[0m"
# define COLOR_PCE "\033[48;2;173;226;93m\033[30m%c\033[0m"
# define COLOR_WALL "\033[48;2;108;169;189m\033[30m%c\033[0m"

/**
 * @brief Error codes that are used to identify corresponding error message and
 * are also used as exit program value
 */
typedef enum e_error
{
	OK = 0,
	ERR_ARGS,
	ERR_NAME,
	ERR_EXT,
	ERR_OPEN,
	ERR_EMPTY_MAP,
	ERR_MAP_SIZE,
	ERR_RECT,
	ERR_WALL,
	ERR_CHAR,
	ERR_PLAYER,
	ERR_EXIT,
	ERR_COL,
	ERR_UNREACH,
	ERR_FRAME_DIMENSION,
	ERR_MAX
}	t_error;

/*==============================================================================
                                ERROR MANAGEMENT                                
==============================================================================*/

/**
 * @brief Take an error code and look in the error_message table for the 
 * correspongind message
 * 
 * @param error_code The error code
 * @return The corresponding error message
 */
char	*get_error_message(t_error error_code);

/**
 * @brief Put an error mesage in the standard error file descriptor and exit
 * the program
 * 
 * @param error_code The error code
 */
void	error(t_error error_code);

/**
 * @brief Print the global error variable of the mlx library and exit
 * the program
 */
void	mlx_error(void);

#endif