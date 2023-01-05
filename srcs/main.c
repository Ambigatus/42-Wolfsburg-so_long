/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:12:29 by ddzuba            #+#    #+#             */
/*   Updated: 2023/01/05 16:28:07 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render(t_data *data);
static int	keyhandler(int keycode, t_data *data);
static int	rkeyhandler(int keycode, t_data *data);
static void	initial(t_data *data, char *filename);

/* Main function, whats just start everything. Simple, isn't? */
int	main(int argc, char **argv)
{
	t_data	data;
	char	*filename;

	if (argc == 1)
		filename = MAP_FILE;
	else
		filename = argv[1];
	data.bsize = TILE_SIZE;
	initial(&data, filename);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L << 0, &keyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_RELEASE, 1L << 1, &rkeyhandler, &data);
	mlx_hook(data.win, X_EVENT_KEY_EXIT, 1L << 0, &close_game, &data);
	mlx_loop(data.mlx);
	return (0);
}

/* Starts initialization of game. Loading file, map, tiles... */
static void	initial(t_data *data, char *filename)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		error_game(data, ERROR_MLX, NULL);
	load_file(data, filename);
	load_map(data);
	has_valid_path(data);
	load_tiles(data);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "So_long...");
	if (!data->win)
		error_game(data, ERROR_WIN, NULL);
	load_game(data);
}

/* Main render of the game. Checks FRAME_RATE and spawn time */
static int	render(t_data *data)
{
	if (data->frame == FRAME_RATE)
	{
		data->frame = 0;
		data->stime += 1;
		if (data->stime % SPAWN_RATE == 0)
			respawn_enemies(data);
	}
	else
		data->frame += 1;
	render_game(data);
	check_player(data);
	return (0);
}

/* Keyboard handling. Checks input keys */
static int	keyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_LEFT || keycode == KEY_A)
		moving_handling(data, DIRCT_LEFT);
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		moving_handling(data, DIRCT_RIGHT);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		moving_handling(data, DIRCT_DOWN);
	if (keycode == KEY_UP || keycode == KEY_W)
		moving_handling(data, DIRCT_UP);
	if (keycode == KEY_SPACE)
		space_handling(data);
	if (keycode == KEY_CTRL)
		ctrl_handling(data, 0);
	if (keycode == KEY_ENTER)
		enter_handling(data);
	if (keycode == KEY_ESC)
		exit_game(data, EXIT_SUCCEED);
	return (0);
}

/* Keyboard handling. Checks input keys, part 2 */
static int	rkeyhandler(int keycode, t_data *data)
{
	if (keycode == KEY_CTRL)
		ctrl_handling(data, 1);
	return (0);
}
