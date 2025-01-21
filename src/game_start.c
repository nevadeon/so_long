#include "so_long.h"

static void	place_tile(t_game_env *env, mlx_image_t *tile, size_t x, size_t y)
{
	size_t	instance_index;

	instance_index = image_to_window(env->mlx, tile, 0, 0);
	tile->instances[instance_index].x = \
		WIDTH / 2 + ((x - env->map.player_x) * TILE_SIZE - TILE_SIZE / 2);
	tile->instances[instance_index].y = \
		HEIGHT / 2 + ((y - env->map.player_y) * TILE_SIZE);
}

static void	display_ground(t_game_env *env)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (env->map.grid[++y] != NULL)
	{
		x = -1;
		while (env->map.grid[y][++x] != '\0')
		{
			if (env->map.grid[y][x] == '1')
				place_tile(env, env->water, x, y);
			else
				place_tile(env, env->sand, x, y);
		}
	}
}

static void	display_collectible_exit(t_game_env *env)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (env->map.grid[++y] != NULL)
	{
		x = -1;
		while (env->map.grid[y][++x] != '\0')
		{
			if (env->map.grid[y][x] == 'C')
				place_tile(env, env->steak, x, y);
			if (env->map.grid[y][x] == 'E')
				place_tile(env, env->exit, x, y);
		}
	}
}

void	start_game(t_game_env *env)
{
	env->map.player_pos_x = env->map.player_x * TILE_SIZE + TILE_SIZE / 2;
	env->map.player_pos_y = env->map.player_y * TILE_SIZE + TILE_SIZE / 2;
	display_ground(env);
	display_collectible_exit(env);
	image_to_window(env->mlx, env->menu_bg_anim.render_layer, 0, 0);
	image_to_window(env->mlx, env->start_bt,
		get_button_coords(BTN_START, X), get_button_coords(BTN_START, Y));
	image_to_window(env->mlx, env->exit_bt,
		get_button_coords(BTN_EXIT, X), get_button_coords(BTN_EXIT, Y));
	image_to_window(env->mlx, env->foreground, 0, 0);
}
