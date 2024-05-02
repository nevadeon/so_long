/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:46:30 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/02 17:05:01 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "libndav.h"
# include "MLX42.h"

# define WINDOW_TITLE "so_long"
# define WIDTH 861
# define HEIGHT 633

# define MENU_SPRITE "assets/menu/menu_sprite.png"
# define MENU_BACKGROUND "assets/menu/background.png"
# define SELECT_SPRITE "assets/menu/selected.png"
# define START_BUTTON "assets/menu/start.png"
# define EXIT_BUTTON "assets/menu/exit.png"

# define NB_SLICES 3
# define SLICE_WIDTH 
# define SLICE_HEIGHT
# define DELAY_MS 120

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*menu_bg;
	mlx_image_t	*start_bt;
	mlx_image_t	*exit_bt;
	mlx_image_t	*foreground;
	t_animation	*select_anim;
}	t_game;

typedef struct s_animation {
	mlx_image_t **frames;
	uint32_t	current_frame;
}	t_animation;

typedef struct s_sprite {
	char		*file_path;
	uint32_t	frame_width;
	uint32_t	frame_height;
	uint32_t	padding_x;
	uint32_t	padding_y;
	uint32_t	nb_collumns;
	uint32_t	nb_rows;
	uint32_t	nb_frames;
	mlx_image_t	*img;
}	t_sprite;

mlx_image_t	*load_image(mlx_t *mlx, int width, int height);
mlx_image_t	*load_png(mlx_t	*mlx, char *file_path);
t_animation	*load_sprite(mlx_t *mlx, t_sprite *sprite);

#endif