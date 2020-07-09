/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:56:37 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:56:38 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "keys.h"

extern int	**g_worldmap;

void	move_forward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.1;
	if (g_worldmap[(int)(fov->posx + fov->dirx
			* movespeed)][(int)(fov->posy)] == 0)
		fov->posx += fov->dirx * movespeed;
	if (g_worldmap[(int)(fov->posx)]
			[(int)(fov->posy + fov->diry * movespeed)] == 0)
		fov->posy += fov->diry * movespeed;
}

void	move_backward(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.1;
	if (g_worldmap[(int)(fov->posx - fov->dirx * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->dirx * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->diry * movespeed)] == 0)
		fov->posy -= fov->diry * movespeed;
}

void	move_right(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.1;
	if (g_worldmap[(int)(fov->posx + fov->planex * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx += fov->planex * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy + fov->planey * movespeed)] == 0)
		fov->posy += fov->planey * movespeed;
}

void	move_left(t_fov *fov)
{
	double	movespeed;

	movespeed = 0.1;
	if (g_worldmap[(int)(fov->posx - fov->planex * movespeed)]
		[(int)(fov->posy)] == 0)
		fov->posx -= fov->planex * movespeed;
	if (g_worldmap[(int)(fov->posx)]
		[(int)(fov->posy - fov->planey * movespeed)] == 0)
		fov->posy -= fov->planey * movespeed;
}
