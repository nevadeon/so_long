#include "so_long.h"

void	update_instances_positions(mlx_image_t	*image, long dx, long dy)
{
	size_t	i;

	i = 0;
	while (i < image->count)
	{
		image->instances[i].x += dx;
		image->instances[i].y += dy;
		i++;
	}
}

void update_knight_status(t_game_env *env, long dx, long dy)
{
	bool	is_moving;
	bool	is_going_left;
	
	is_moving = (dx != 0 || dy != 0);
	is_going_left = (dx > 0);
	if (is_moving)
	{
		if (env->knight_status == IDLE)
		{
			env->knight_status = MOVING;
			env->moving_knight.needs_refresh = true;
		}
		env->idle_knight.mirrored = is_going_left;
		env->moving_knight.mirrored = is_going_left;
	}
	else
	{
		if (env->knight_status == MOVING)
		{
			env->knight_status = IDLE;
			env->moving_knight.current_frame = 0;
		}
	}
}

void	update_positions(t_game_env *env)
{
	long			dx;
	long			dy;

	dx = 0;
	dy = 0;
	if (mlx_is_key_down(env->mlx, MLX_KEY_UP))
		dy += 10;
	if (mlx_is_key_down(env->mlx, MLX_KEY_DOWN))
		dy -= 10;
	if (mlx_is_key_down(env->mlx, MLX_KEY_LEFT))
		dx += 10;
	if (mlx_is_key_down(env->mlx, MLX_KEY_RIGHT))
		dx -= 10;
	if (dx != 0 && dy != 0)
	{
		dx /= 1.4;
		dy /= 1.4;
	}
	update_knight_status(env, dx, dy);
	update_instances_positions(env->water, dx, dy);
	update_instances_positions(env->sand, dx, dy);
}

void	in_game_update(t_game_env *env)
{
	static double	elapsed_time_ms = 0;

	elapsed_time_ms += env->mlx->delta_time * 1000;
	if (elapsed_time_ms >= 10)
	{
		dprintf(2, "in\n");
		update_positions(env);
		elapsed_time_ms -= 10;
	}
	else
		dprintf(2, "out\n");
	if (env->knight_status == MOVING)
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
