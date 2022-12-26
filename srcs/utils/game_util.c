/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 13:15:29 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/09 18:57:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	grid_loop_util(t_data *data, void (*f)(t_data*, t_tile))
{
	t_tile	t;
	int		gx;
	int		gy;

	gy = 0;
	while (gy < data->map.grid_y)
	{
		gx = 0;
		while (gx < data->map.grid_x)
		{
			t = data->map.tiles[gy][gx];
			f(data, t);
			gx++;
		}
		gy++;
	}
}

void	add_sprt_list(t_sprt *list, t_sprt *new)
{
	t_sprt	*tmp;

	if (!list)
		list = new;
	else
	{
		tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	render_sprts_util(t_data *data, t_sprt *s)
{
	while (s)
	{
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	render_sprts_fnc_util(t_data *data, t_sprt *s,
	void (*f)(t_data*, t_sprt*))
{
	while (s)
	{
		f(data, s);
		if (s->img.mlx)
			mlx_put_image_to_window(
				data->mlx, data->win, s->img.mlx, s->v.x, s->v.y);
		s = s->next;
	}
}

void	free_sprts_util(t_data *data, t_sprt *s)
{
	t_sprt	*tmp;

	tmp = s;
	while (tmp)
	{
		if (tmp->img.mlx)
			mlx_destroy_image(data->mlx, tmp->img.mlx);
		tmp = tmp->next;
	}
}
