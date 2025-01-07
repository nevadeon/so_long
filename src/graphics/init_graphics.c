#include "so_long.h"

void	init_select_anim(t_game_env *env)
{
	t_sprite	select_sprite;

	select_sprite = (t_sprite){
		.file_path = PATH_SELECT_SPRITE,
		.nb_frames = 4,
		.frame_width = 217,
		.frame_height = 150,
		.padding_x = 0,
		.padding_y = 0
	};
	env->select_anim = (t_animation){
		.render_layer = env->foreground,
		.update_delay_ms = 300,
		.time_counter_ms = 0
	};
	load_animation(env->mlx, &env->select_anim, &select_sprite);
}

void	init_menu_bg_anim(t_game_env *env)
{
	t_sprite	menu_bg_sprite;

	menu_bg_sprite = (t_sprite){
		.file_path = PATH_MENUBG_SPRITE,
		.nb_frames = 24,
		.frame_width = 1309,
		.frame_height = 995,
		.padding_x = 10,
		.padding_y = 10
	};
	env->menu_bg_anim = (t_animation){
		.render_layer = new_image(env->mlx, WIDTH, HEIGHT),
		.update_delay_ms = 120,
		.time_counter_ms = 0
	};
	load_animation(env->mlx, &env->menu_bg_anim, &menu_bg_sprite);
}

void	init_idle_knight_anim(t_game_env *env)
{
	t_sprite	idle_knight_sprite;

	idle_knight_sprite = (t_sprite){
		.file_path = PATH_IDLE_KNIGHT_SPRITE,
		.nb_frames = 6,
		.frame_width = 192,
		.frame_height = 192,
		.padding_x = 0,
		.padding_y = 0
	};
	env->idle_knight = (t_animation){
		.render_layer = env->foreground,
		.update_delay_ms = 120,
		.time_counter_ms = 0
	};
	load_animation(env->mlx, &env->idle_knight, &idle_knight_sprite);
}

void	init_moving_knight_anim(t_game_env *env)
{
	t_sprite	moving_knight_sprite;

	moving_knight_sprite = (t_sprite){
		.file_path = PATH_MOVING_KNIGHT_SPRITE,
		.nb_frames = 6,
		.frame_width = 192,
		.frame_height = 192,
		.padding_x = 0,
		.padding_y = 0
	};
	env->moving_knight = (t_animation){
		.render_layer = env->foreground,
		.update_delay_ms = 120,
		.time_counter_ms = 0
	};
	load_animation(env->mlx, &env->moving_knight, &moving_knight_sprite);
}

void	init_graphics(t_game_env *env)
{
	mlx_t		*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, WINDOW_TITLE, false);
	if (!mlx)
		handle_mlx_error();
	*env = (t_game_env){
		.mlx = mlx,
		.foreground = new_image(mlx, WIDTH, HEIGHT),
		.start_bt = image_from_png(mlx, PATH_START_BUTTON),
		.exit_bt = image_from_png(mlx, PATH_EXIT_BUTTON),
		.game_status = IN_MENU,
		.selected_button = BTN_START,
		.knight_status = IDLE,
		.mov_status = false
	};
	init_menu_bg_anim(env);
	init_select_anim(env);
	init_idle_knight_anim(env);
	init_moving_knight_anim(env);
}
