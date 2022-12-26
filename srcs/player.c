/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:23:55 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/10 17:07:05 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Player rendering - moving, collecting, hurting */
void	render_player(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.act == ACT_HURTING)
		player_hurting(data);
	else if (p.act == ACT_WALK)
	{
		player_moving(data);
		player_walking(data);
	}
	else if (p.act == ACT_INTERACT)
		player_interacting(data);
	else if (p.act == ACT_STAND)
		player_standing(data);
	else if (p.act == ACT_COLLECTED)
		player_collecting(data);
	else
		player_switch_acting(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->player.img.mlx, data->player.v.x, data->player.v.y);
}

/* Checks the status of player. If enemy tile overlap player tile, */
/* player die. If player hide, do nothing */
void	check_player(t_data *data)
{
	t_sprt	p;
	t_sprt	*e;

	p = data->player;
	if (p.act == ACT_SLEEP)
		return ;
	e = data->enemies;
	while (e)
	{
		if (is_ovelap_tile(e->v, p.v, 0, 0))
		{
			if (p.act != ACT_HURTING && p.act != ACT_FALLEN)
				player_hurting(data);
		}
		e = e->next;
	}
}

/* Checks the collectible tiles. If true, you can collect it. */
void	check_object_player(t_data *data, t_tile t)
{
	t_sprt	*obj;

	obj = data->objs;
	while (obj)
	{
		if (obj->v.x == t.v.x && obj->v.y == t.v.y && t.type == 'C')
		{
			if (obj->img.mlx)
			{
				mlx_destroy_image(data->mlx, obj->img.mlx);
				obj->img.mlx = NULL;
				data->player.act = ACT_COLLECTED;
				data->player.item++;
			}
			return ;
		}
		obj = obj->next;
	}
}
