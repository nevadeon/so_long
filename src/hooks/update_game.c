#include "so_long.h"

void	update_instances_positions(mlx_image_t	*image, long dx, long dy)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		image->instances[i].x -= dx;
		image->instances[i].y -= dy;
		i++;
	}
}

void	disable_outofview_instances(mlx_image_t *image)
{
	size_t	i;
	i = 0;
	while (i < image->count)
	{
		if (image->instances[i].x < 0 - TILE_SIZE
			|| image->instances[i].x > WIDTH
			|| image->instances[i].y < 0 - TILE_SIZE
			|| image->instances[i].y > HEIGHT)
			image->instances[i].enabled = false;
		else
			image->instances[i].enabled = true;
		i++;
	}
}

void	check_wall_collision(t_game_map map, long *dx, long *dy)
{
	size_t	current_x;
	size_t	current_y;
	size_t	futur_x;
	size_t	futur_y;

	current_x = map.player_pos_x / TILE_SIZE;
	current_y = map.player_pos_y / TILE_SIZE;
	if (*dx < 0)
		futur_x = (map.player_pos_x - 10 + *dx) / TILE_SIZE;
	else
		futur_x = (map.player_pos_x + 10 + *dx) / TILE_SIZE;
	futur_y = (map.player_pos_y + *dy) / TILE_SIZE;
	if (map.grid[current_y][futur_x] == '1')
		*dx = 0;
	if (map.grid[futur_y][current_x] == '1')
		*dy = 0;
}

void	update_positions(t_game_env *env)
{
	long	dx;
	long	dy;

	dx = 0;
	dy = 0;
	if (env->player.is_up)
		dy -= 5;
	if (env->player.is_down)
		dy += 5;
	if (env->player.is_left)
		dx -= 5;
	if (env->player.is_right)
		dx += 5;
	check_wall_collision(env->map, &dx, &dy);
	if (dx != 0 && dy != 0)
	{
		dx /= 1.4;
		dy /= 1.4;
	}
	env->map.player_pos_x += dx;
	env->map.player_pos_y += dy;
	update_instances_positions(env->water, dx, dy);
	update_instances_positions(env->sand, dx, dy);
}

//TODO add collectibles and exit collisions
void	in_game_update(t_game_env *env)
{
	static double	elapsed_time_ms = 0;

	elapsed_time_ms += env->mlx->delta_time * 1000;
	if (elapsed_time_ms >= 15)
	{
		update_positions(env);
		disable_outofview_instances(env->sand);
		disable_outofview_instances(env->water);
		elapsed_time_ms -= 15;
	}
	if (env->player.is_moving)
		update_animation(&env->moving_knight, env->mlx->delta_time);
	else
		update_animation(&env->idle_knight, env->mlx->delta_time);
}

void	in_menu_update(t_game_env *env)
{
	env->select_anim.dest_x = get_button_coords(env->selected_button, X);
	env->select_anim.dest_y = get_button_coords(env->selected_button, Y);
	update_animation(&env->select_anim, env->mlx->delta_time);
	update_animation(&env->menu_bg_anim, env->mlx->delta_time);
}

void	update_game(void *param)
{
	t_game_env	*env;

	env = (t_game_env *) param;
	if (env->game_status == IN_MENU)
		in_menu_update(env);
	else if (env->game_status == PLAYING)
		in_game_update(env);
}
