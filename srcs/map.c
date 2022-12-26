/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 09:36:34 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/26 15:02:31 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_map_data(t_data *data, int is_init);

/* Inside utility function for making new tile */
static t_tile	new_tile(char type, int x, int y)
{
	t_tile	tile;

	tile.type = type;
	tile.v.x = x;
	tile.v.y = y;
	return (tile);
}

/* Loading map data from map file and update inner counters for stuff */
void	load_map(t_data *data)
{
	char	*f;

	f = data->map.filedata;
	init_map_data(data, 1);
	while (*f)
	{
		while (*f && *f != '\n')
		{
			if (data->map.grid_y == 0)
				data->map.grid_x++;
			if (*f == 'C')
				data->map.item++;
			else if (*f == 'E')
				data->map.exit++;
			else if (*f == 'P')
				data->map.player++;
			else if (*f == 'M')
				data->map.enemy++;
			f++;
		}
		data->map.grid_y++;
		f++;
	}
	init_map_data(data, 0);
	validate_map(data);
	has_valid_path(data);
}

/* Puts on map tiles by their types and using malloc for each of them */
void	load_tiles(t_data *data)
{
	char	*str;
	int		gx;
	int		gy;

	data->map.tiles = malloc(sizeof(t_tile *) * data->map.grid_y);
	gy = 0;
	str = data->map.filedata;
	while (*str)
	{
		gx = 0;
		data->map.tiles[gy] = malloc(sizeof(t_tile) * data->map.grid_x);
		while (*str != '\n' && *str)
		{
			data->map.tiles[gy][gx] = new_tile(
					*str, gx * data->bsize, gy * data->bsize);
			gx++;
			str++;
		}
		str++;
		gy++;
	}
}

/* Freeing map tiles */
void	free_map_tiles(t_data *data)
{
	int		gy;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		free(data->map.tiles[gy]);
		gy++;
	}
	free(data->map.tiles);
}

/* Basic initialization of map data, starting by 0 */
static void	init_map_data(t_data *data, int is_init)
{
	if (is_init)
	{
		data->map.grid_x = 0;
		data->map.grid_y = 0;
		data->map.item = 0;
		data->map.exit = 0;
		data->map.player = 0;
		data->map.enemy = 0;
	}
	else
	{
		data->map.width = data->map.grid_x * data->bsize;
		data->map.height = data->map.grid_y * data->bsize;
		data->w = data->map.width;
		data->h = data->map.height + data->bsize;
	}
}
