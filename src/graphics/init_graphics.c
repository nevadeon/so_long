#include "so_long.h"

void	init_select_anim(t_game_env *env)
{
	t_animation	anim;

	anim = (t_animation){
		.render_layer = env->foreground,
		.sprite_sheet = texture_from_png(PATH_SELECT),
		.frame_count = 4,
		.frame_width = 217,
		.frame_height = 150,
		.frame_duration_ms = 300,
	};
	env->select_anim = anim;
}

void	init_menu_bg_anim(t_game_env *env)
{
	t_animation	anim;

	anim = (t_animation){
		.render_layer = new_image(env->mlx, WIDTH, HEIGHT),
		.sprite_sheet = texture_from_png(PATH_MENU_BG),
		.frame_count = 24,
		.frame_duration_ms = 120,
		.frame_width = 1309,
		.frame_height = 995,
		.padding_x = 10,
		.padding_y = 10,
	};
	env->menu_bg_anim = anim;
}

void	init_idle_knight_anim(t_game_env *env)
{
	t_animation	anim;

	anim = (t_animation){
		.render_layer = env->foreground,
		.sprite_sheet = texture_from_png(PATH_BLUE_KNIGHT),
		.start_frame = 0,
		.frame_count = 6,
		.frame_width = 192,
		.frame_height = 192,
		.frame_duration_ms = 120,
	};
	anim.dest_x = WIDTH / 2 - anim.frame_width / 2;
	anim.dest_y = HEIGHT / 2 - anim.frame_height / 2;
	env->idle_knight = anim;
}

void	init_moving_knight_anim(t_game_env *env)
{
	t_animation	anim;

	anim = (t_animation){
		.render_layer = env->foreground,
		.sprite_sheet = texture_from_png(PATH_BLUE_KNIGHT),
		.start_frame = 6,
		.frame_count = 6,
		.frame_width = 192,
		.frame_height = 192,
		.frame_duration_ms = 120,
	};
	anim.dest_x = WIDTH / 2 - anim.frame_width / 2;
	anim.dest_y = HEIGHT / 2 - anim.frame_height / 2;
	env->moving_knight = anim;
}

void	init_graphics(t_game_env *env, t_game_map map)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*env = (t_game_env){
		.mlx = mlx,
		.map = map,
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.start_bt = image_from_png(mlx, PATH_START_BUTTON),
		.exit_bt = image_from_png(mlx, PATH_EXIT_BUTTON),
		.water = image_from_png(mlx, PATH_WATER),
		.sand = image_from_png(mlx, PATH_SAND),
		.exit = image_from_png(mlx, PATH_EXIT),
		.steak = image_from_png(mlx, PATH_STEAK),
		.game_status = IN_MENU,
		.selected_button = BTN_START,
	};
	init_menu_bg_anim(env);
	init_select_anim(env);
	init_idle_knight_anim(env);
	init_moving_knight_anim(env);
}
