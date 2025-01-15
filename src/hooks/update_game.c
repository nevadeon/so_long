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

void	update_knight_status(t_game_env *env, long dx, long dy)
{
	bool	is_moving;
	bool	is_moving_horizontaly;
	bool	is_going_left;

	is_moving = (dx != 0 || dy != 0);
	is_moving_horizontaly = (dx != 0);
	is_going_left = (dx < 0);
	if (is_moving)
	{
		if (env->is_player_moving == IDLE)
		{
			env->is_player_moving = MOVING;
			env->moving_knight.needs_refresh = true;
		}
		if (is_moving_horizontaly)
		{
			env->idle_knight.mirrored = is_going_left;
			env->moving_knight.mirrored = is_going_left;
		}
	}
	else if (env->is_player_moving == MOVING)
	{
		env->is_player_moving = IDLE;
		env->moving_knight.current_frame = 0;
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
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
		dy -= 5;
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
		dy += 5;
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		dx -= 5;
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		dx += 5;
	check_wall_collision(env->map, &dx, &dy);
	if (dx != 0 && dy != 0)
	{
		dx /= 1.4;
		dy /= 1.4;
	}
	env->map.player_pos_x += dx;
	env->map.player_pos_y += dy;
	update_knight_status(env, dx, dy);
	update_instances_positions(env->water, dx, dy);
	update_instances_positions(env->sand, dx, dy);
}

void	disable_outofview_instances(t_game_map map, mlx_image_t *image)
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

void	in_game_update(t_game_env *env)
{
	static double	elapsed_time_ms = 0;

	elapsed_time_ms += env->mlx->delta_time * 1000;
	if (elapsed_time_ms >= 10)
	{
		update_positions(env);
		disable_outofview_instances(env->map, env->sand);
		disable_outofview_instances(env->map, env->water);
		elapsed_time_ms -= 10;
	}
	if (env->is_player_moving == MOVING)
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
