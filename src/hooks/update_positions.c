#include "so_long.h"

static void	update_instances_positions(mlx_image_t	*image, long dx, long dy)
{
	uint32_t	i;

	i = 0;
	while (i < image->count)
	{
		image->instances[i].x -= dx;
		image->instances[i].y -= dy;
		i++;
	}
}

static void	disable_colliding_instances(mlx_image_t	*image)
{
	t_uint	i;

	i = 0;
	while (i < image->count)
	{
		if ((image->instances[i].x / 64 >= (WIDTH / 2 - 64) / 64) \
			&& (image->instances[i].x / 64 <= (WIDTH / 2) / 64)
			&& (image->instances[i].y / 64 >= (HEIGHT / 2 - 32) / 64)
			&& (image->instances[i].y / 64 <= (HEIGHT / 2 + 32) / 64))
		{
			image->instances[i].enabled = false;
		}
		i++;
	}
}

static void	handle_collectible_and_exit(t_game_env *env, long dx, long dy)
{
	uint32_t	futur_x;
	uint32_t	futur_y;

	futur_x = (env->map.player_pos_x + dx) / TILE_SIZE;
	futur_y = (env->map.player_pos_y + dy) / TILE_SIZE;
	if (env->map.grid[futur_y][futur_x] == 'C')
	{
		env->map.nb_collectibles--;
		env->map.grid[futur_y][futur_x] = '0';
		disable_colliding_instances(env->steak);
	}
	if (env->map.grid[futur_y][futur_x] == 'E' && env->map.nb_collectibles == 0)
		exit_game(env);
}

static void	check_wall_collision(t_game_env *env, long *dx, long *dy)
{
	uint32_t	current_x;
	uint32_t	current_y;
	uint32_t	futur_x;
	uint32_t	futur_y;

	current_x = env->map.player_pos_x / TILE_SIZE;
	current_y = env->map.player_pos_y / TILE_SIZE;
	futur_x = (env->map.player_pos_x + *dx) / TILE_SIZE;
	futur_y = (env->map.player_pos_y + *dy) / TILE_SIZE;
	if ((futur_x - current_x) == 0 && (futur_y - current_y) == 0)
		return ;
	if (env->map.grid[current_y][futur_x] == '1')
		*dx = 0;
	if (env->map.grid[futur_y][current_x] == '1')
		*dy = 0;
	if (env->map.grid[current_y][futur_x] != '1'
		&& env->map.grid[futur_y][current_x] != '1')
		ft_dprintf(2, "%d\n", env->map.move_counter++);
	handle_collectible_and_exit(env, *dx, *dy);
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
	check_wall_collision(env, &dx, &dy);
	if (dx != 0 && dy != 0)
	{
		dx /= 1.4;
		dy /= 1.4;
	}
	env->map.player_pos_x += dx;
	env->map.player_pos_y += dy;
	update_instances_positions(env->water, dx, dy);
	update_instances_positions(env->sand, dx, dy);
	update_instances_positions(env->steak, dx, dy);
	update_instances_positions(env->exit, dx, dy);
}
