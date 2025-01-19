#include "so_long.h"

void	display_ground(t_game_env *env)
{
	size_t	instance_index;
	size_t	x;
	size_t	y;

	y = -1;
	while (env->map.grid[++y] != NULL)
	{
		x = -1;
		while (env->map.grid[y][++x] != '\0')
		{
			if (env->map.grid[y][x] == '1')
			{
				instance_index = image_to_window(env->mlx, env->water, 0, 0);
				env->water->instances[instance_index].x = WIDTH / 2 + ((x - env->map.player_x) * TILE_SIZE - TILE_SIZE / 2);
				env->water->instances[instance_index].y = HEIGHT / 2 + ((y - env->map.player_y) * TILE_SIZE);
			}
			else
			{
				instance_index = image_to_window(env->mlx, env->sand, 0, 0);
				env->sand->instances[instance_index].x = WIDTH / 2 + ((x - env->map.player_x) * TILE_SIZE - TILE_SIZE / 2);
				env->sand->instances[instance_index].y = HEIGHT / 2 + ((y - env->map.player_y) * TILE_SIZE);
			}

		}
	}
}

void	display_collectible_exit(t_game_env *env)
{
	size_t	instance_index;
	size_t	x;
	size_t	y;

	y = -1;
	while (env->map.grid[++y] != NULL)
	{
		x = -1;
		while (env->map.grid[y][++x] != '\0')
		{
			if (env->map.grid[y][x] == 'C')
			{
				instance_index = image_to_window(env->mlx, env->steak, 0, 0);
				env->steak->instances[instance_index].x = WIDTH / 2 + ((x - env->map.player_x) * TILE_SIZE - TILE_SIZE / 2);
				env->steak->instances[instance_index].y = HEIGHT / 2 + ((y - env->map.player_y) * TILE_SIZE);

			}
			if (env->map.grid[y][x] == 'E')
			{
				instance_index = image_to_window(env->mlx, env->exit, 0, 0);
				env->exit->instances[instance_index].x = WIDTH / 2 + ((x - env->map.player_x) * TILE_SIZE - TILE_SIZE / 2);
				env->exit->instances[instance_index].y = HEIGHT / 2 + ((y - env->map.player_y) * TILE_SIZE);
			}
		}
	}
}

void	start_game(t_game_env *env)
{
	env->map.player_pos_x = env->map.player_x * TILE_SIZE + TILE_SIZE / 2;
	env->map.player_pos_y = env->map.player_y * TILE_SIZE + TILE_SIZE / 2;
	env->map.move_counter = 0;
	display_ground(env);
	display_collectible_exit(env);
	image_to_window(env->mlx, env->menu_bg_anim.render_layer, 0, 0);
	image_to_window(env->mlx, env->start_bt,
		get_button_coords(BTN_START, X), get_button_coords(BTN_START, Y));
	image_to_window(env->mlx, env->exit_bt,
		get_button_coords(BTN_EXIT, X), get_button_coords(BTN_EXIT, Y));
	image_to_window(env->mlx, env->foreground, 0, 0);
}
