/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddzuba <ddzuba@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:15:46 by ddzuba            #+#    #+#             */
/*   Updated: 2022/12/12 17:11:12 by ddzuba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Basic vector structure for correct moving */
t_vtr	set_vtr(int x, int y)
{
	t_vtr	v;

	v.x = x;
	v.y = y;
	return (v);
}

/* Add new vector when player/enemy moves. Needs for correct moving */
t_vtr	add_vtr(t_vtr v1, t_vtr v2)
{
	t_vtr	v3;

	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	return (v3);
}

/* Basic moves logic for player/enemy */
t_vtr	get_move_vtr(int drct, int msize)
{
	t_vtr	v;
	int		m;

	v.x = 0;
	v.y = 0;
	if (msize == 0)
		m = TILE_SIZE;
	else
		m = msize * TILE_SIZE / 32;
	if (drct == DIRCT_LEFT)
		v.x = m * -1;
	if (drct == DIRCT_RIGHT)
		v.x = m;
	if (drct == DIRCT_UP)
		v.y = m * -1;
	if (drct == DIRCT_DOWN)
		v.y = m;
	return (v);
}
