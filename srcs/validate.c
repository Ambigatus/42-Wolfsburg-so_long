/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:35:05 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/12 17:45:28 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	valid_wall(t_map map);

/* File validation - checking map extansion */
int	validate_file_ext(char *filename)
{
	int		len;
	char	*ext;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	ext = filename + (len - 4);
	return (!ft_strncmp(".ber", ext, 4));
}

/* Map validation - cheking requirements of map: size, items, player etc */
void	validate_map(t_data *data)
{
	t_map	m;

	m = data->map;
	if (m.grid_x * m.grid_y < 4 * 4)
		error_game(data, ERROR_MAP_INVALID, "Map is too small!");
	if (ft_strlen_int(m.filedata) != m.grid_x * m.grid_y + m.grid_y - 1)
		error_game(data, ERROR_MAP_INVALID, "Map is not rectangle!");
	if (m.item == 0 || m.player == 0 || m.exit != 1)
		error_game(data, ERROR_MAP_INVALID, "ERROR: map hasn't min requir!");
	if (valid_wall(data->map) == 0)
		error_game(data, ERROR_MAP_INVALID, "Map not covered with wall!");
}

/* Map validation - cheking map by covering the walls */
static int	valid_wall(t_map map)
{
	int		i;
	int		x;
	int		y;
	char	*f;

	i = 0;
	x = 0;
	y = 0;
	f = map.filedata;
	while (f[i])
	{
		x = 0;
		while (f[i] && f[i] != '\n')
		{
			if ((x == 0 || x == map.grid_x - 1) && f[i] != '1')
				return (0);
			if ((y == 0 || y == map.grid_y -1) && f[i] != '1')
				return (0);
			i++;
			x++;
		}
		i++;
		y++;
	}
	return (1);
}
