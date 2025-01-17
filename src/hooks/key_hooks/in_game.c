#include "so_long.h"

void	update_player_status(t_game_env *env, t_player_data *player)
{
	player->is_left = mlx_is_key_down(env->mlx, MLX_KEY_LEFT);
	player->is_right = mlx_is_key_down(env->mlx, MLX_KEY_RIGHT);
	player->is_up = mlx_is_key_down(env->mlx, MLX_KEY_UP);
	player->is_down = mlx_is_key_down(env->mlx, MLX_KEY_DOWN);
	if (player->is_left && player->is_right)
	{
		player->is_left = false;
		player->is_right = false;
	}
	if (player->is_up && player->is_down)
	{
		player->is_up = false;
		player->is_down = false;
	}
	player->is_moving = (player->is_left || player->is_right
		|| player->is_up || player->is_down);
}

void	update_knight_animation(t_game_env *env, t_player_data *player)
{
	if (player->is_moving)
	{
		if (!player->was_moving)
		{
			player->was_moving = true;
			env->moving_knight.needs_refresh = true;
		}
		if (player->is_left || player->is_right)
		{
			env->idle_knight.mirrored = player->is_left;
			env->moving_knight.mirrored = player->is_left;
		}
	}
	else if (player->was_moving)
	{
		player->was_moving = false;
		env->moving_knight.current_frame = 0;
	}
}

void	in_game_key_logic(mlx_key_data_t keydata, t_game_env *env)
{
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		env->game_status = IN_MENU;
		env->menu_bg_anim.render_layer->enabled = true;
		env->start_bt->enabled = true;
		env->exit_bt->enabled = true;
		env->water->enabled=false;
		env->sand->enabled=false;
		env->select_anim.needs_refresh = true;
	}
	update_player_status(env, &env->player);
	update_knight_animation(env, &env->player);
}
