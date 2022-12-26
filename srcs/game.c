/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_Macos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:17:12 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/26 16:10:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Loading all map and game data for starting the programm */
void	load_game(t_data *data)
{
	data->objs = NULL;
	data->bg = NULL;
	data->enemies = NULL;
	data->frame = 0;
	data->stime = 0;
	grid_loop_util(data, &new_bg);
	load_panel(data);
	load_score(data);
	grid_loop_util(data, &new_obj);
	grid_loop_util(data, &new_player);
	grid_loop_util(data, &new_enemy);
}

/* Sprites render for all objects */
void	render_game(t_data *data)
{
	render_sprts_util(data, data->bg);
	render_sprts_util(data, data->panel.bg);
	render_sprts_util(data, data->panel.score);
	render_sprts_util(data, data->objs);
	render_player(data);
	render_enemies(data);
}

/* Correct exit handling with freeing all using data */
void	exit_game(t_data *data, int code)
{
	ft_printf("Exit Game\n");
	free_sprts_util(data, data->bg);
	free_sprts_util(data, data->objs);
	free_sprts_util(data, data->panel.bg);
	free_sprts_util(data, data->panel.score);
	free_sprts_util(data, data->enemies);
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	free_map_tiles(data);
	if (data->map.filedata)
		free(data->map.filedata);
	exit(code);
}

/* Errors handling, using with ERROR_CODE */
void	error_game(t_data *data, int code, char *msg)
{
	if (code == ERROR_FILE_OPEN || code == ERROR_MAP_INVALID)
		ft_printf("Error: %s\n", msg);
	else if (code == ERROR_MLX)
	{
		ft_printf("Error: MLX lib cannot operation\n");
		free(data->mlx);
	}
	else if (code == ERROR_WIN)
	{
		ft_printf("Error: MLX WIN lib cannoot operation\n");
		free(data->mlx);
		free(data->win);
	}
	exit(1);
}

/* Closing the game */
int	close_game(int keycode, t_data *data)
{
	ft_printf("Close Game\n");
	(void)data;
	(void)keycode;
	exit(0);
	return (0);
}
