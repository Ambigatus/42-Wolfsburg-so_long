/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 08:01:48 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/10 17:10:54 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Animation for collecting items. */
void	player_collecting(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.img = set_img(data, SPRITE_KNEEL_PATH);
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_STAND;
		data->player.animating = 0;
	}
}

/* Animation for player dying */
void	player_hurting(t_data *data)
{
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.img = set_img(data, SPRITE_HURT_PATH);
	data->player.act = ACT_HURTING;
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_FALLEN;
		data->player.animating = 0;
	}
}

/* Animation for player hiding/sleeping */
void	player_sleeping(t_data *data)
{
	t_sprt	p;

	p = data->player;
	if (p.act != ACT_STAND)
		return ;
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.act = ACT_SLEEP;
	data->player.img = set_img(data, SPRITE_SLEEP_PATH);
}

/* Animation for player interacting, like opening the door */
void	player_interacting(t_data *data)
{
	t_sprt	p;
	t_tile	t;

	p = data->player;
	mlx_destroy_image(data->mlx, data->player.img.mlx);
	data->player.act = ACT_INTERACT;
	data->player.img = set_img(data, SPRITE_INTERACT_PATH);
	data->player.animating += 1;
	if (data->player.animating == FRAME_RATE / 2)
	{
		data->player.act = ACT_STAND;
		data->player.animating = 0;
		t = get_tile(data, data->player.v);
		p = data->player;
		if (t.type == 'E')
		{
			if (data->map.item == p.item)
				exit_game(data, EXIT_SUCCEED);
		}
	}
}
