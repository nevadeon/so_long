/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevadeon <github@noedavenne.aleeas.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:46:30 by ndavenne          #+#    #+#             */
/*   Updated: 2024/05/10 00:14:56 by nevadeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "so_long.h"
# include "MLX42.h"   //graphic lib
# include "libndav.h"
# include "graphics.h"
# include "errors.h"

# define WINDOW_TITLE "so_long"
# define WIDTH 	861
# define HEIGHT	633

# define MENU_SPRITE	 "assets/menu/menu_sprite.png"
# define MENU_BACKGROUND "assets/menu/background.png"
# define SELECT_SPRITE 	 "assets/menu/selected.png"
# define START_BUTTON 	 "assets/menu/start.png"
# define EXIT_BUTTON 	 "assets/menu/exit.png"

typedef uint32_t	t_uint;

typedef struct s_sprite
{
	char		*file_path;
	int			frame_width;
	int			frame_height;
	uint32_t	padding_x;
	uint32_t	padding_y;
	uint32_t	nb_collumns;
	uint32_t	nb_rows;
	uint32_t	nb_frames;
	mlx_image_t	*image;
}	t_sprite;

typedef struct s_animation
{
	mlx_image_t	**frames;
	uint32_t	current_frame;
}	t_animation;

typedef struct s_game_visuals
{
	mlx_t		*mlx;
	mlx_image_t	*menu_bg;
	mlx_image_t	*start_bt;
	mlx_image_t	*exit_bt;
	mlx_image_t	*foreground;
	t_animation	*select_anim;
}	t_game_visuals;

void		display_menu(t_game_visuals *graphs);
void		init_graphics(t_game_visuals *graphs);
void		free_graphics(t_game_visuals *graphs);

mlx_image_t	*new_image(mlx_t *mlx, uint32_t width, uint32_t height);
mlx_image_t	*load_png(mlx_t	*mlx, char *file_path);
t_animation	*load_animation(mlx_t *mlx, t_sprite *s);

uint32_t	get_pixel_value(mlx_image_t *img, uint32_t x, uint32_t y);

#endif