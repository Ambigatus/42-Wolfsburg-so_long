/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:19:19 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/10 17:33:41 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Moves handling according to pressed keys. Moves counter. */
void	moving_handling(t_data *data, int dirct)
{
	t_tile	nt;
	t_vtr	mv;
	t_vtr	nv;

	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_WALK;
	data->player.face = dirct;
	mv = get_move_vtr(data->player.face, 0);
	nv = add_vtr(data->player.v, mv);
	nt = get_tile(data, nv);
	if (nt.type == '1')
		return ;
	data->player.nv = nv;
	data->player.moved++;
	ft_printf("MOVED: %d\n", data->player.moved);
	update_score(data);
}

/* Space handling for collection items */
void	space_handling(t_data *data)
{
	t_tile	t;
	t_sprt	p;

	p = data->player;
	t = get_tile(data, data->player.v);
	if (p.act == ACT_STAND)
		data->player.act = ACT_SIT;
	else if (p.act == ACT_SIT)
		data->player.act = ACT_STAND;
	if (t.type == 'C')
		check_object_player(data, t);
}

/* Control handling for hiding from enemys */
void	ctrl_handling(t_data *data, int is_release)
{
	if (is_release)
	{
		if (data->player.act == ACT_SLEEP)
		{
			data->player.act = ACT_STAND;
		}
	}
	else
	{
		if (data->player.act == ACT_STAND)
			data->player.act = ACT_SLEEP;
	}
}

/* Enter handling, for oppening doors */
void	enter_handling(t_data *data)
{
	if (data->player.act != ACT_STAND)
		return ;
	data->player.act = ACT_INTERACT;
}
