/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:35:36 by ddzuba            #+#    #+#             */
/*   Updated: 2023/01/05 16:25:54 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	counter(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == 'C') || (map[i][j] == 'E'))
			{
				count++;
			}
			j++;
		}
		i++;
	}
	return (count);
}

char	**create_matrix(char *map_path, t_data *map)
{
	int		fd;
	char	**map2;
	int		h;
	int		w;
	int		counter;

	h = map->map.grid_y;
	w = map->map.grid_x;
	counter = 0;
	fd = open(map_path, O_RDONLY);
	map2 = ft_calloc(1, 1000);
	while (counter < h)
	{
		map2[counter] = malloc(sizeof(char) * w + 1);
		if (!map2[counter])
		{
			free(map2[counter]);
			exit(EXIT_FAILURE);
		}
		read(fd, map2[counter], w + 1);
		map2[counter][w] = '\0';
		counter++;
	}
	map2[counter] = NULL;
	return (map2);
}

void	counting_reachable(t_data *data, int x, int y, int *a)
{
	char	**map_cpy;

	map_cpy = data->map.map_copy;
	if ((y < 0 || y > data->map.grid_y) || (x < 0 || x > data->map.grid_x))
		return ;
	if (map_cpy[y][x] == '1')
		return ;
	if (map_cpy[y][x] == 'C')
		*a += 1;
	if (map_cpy[y][x] == 'E')
		*a += 1;
	map_cpy[y][x] = '1';
	counting_reachable(data, x, y - 1, a);
	counting_reachable(data, x, y + 1, a);
	counting_reachable(data, x - 1, y, a);
	counting_reachable(data, x + 1, y, a);
}

int	has_valid_path(t_data *data)
{
	int		x;
	int		y;
	int		a;
	int		count;
	char	**map_cpy;

	map_cpy = create_matrix(ft_strjoin("maps/", MAP_FILE), data);
	data->map.map_copy = map_cpy;
	a = 0;
	y = 4;
	x = 1;
	count = counter(map_cpy);
	counting_reachable(data, x, y, &a);
	if (count != a)
	{
		write(1, "No valid path", 13);
		exit(EXIT_FAILURE);
	}
	return (0);
}
