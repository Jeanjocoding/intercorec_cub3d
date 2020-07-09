/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fov.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:55:37 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:55:39 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_fov		initialize_fov(t_fov *fov, double posx, double posy)
{
	fov->posx = posx;
	fov->posy = posy;
	fov->dirx = 1;
	fov->diry = 0;
	fov->planex = 0;
	fov->planey = 0.66;
	fov->time = 0;
	fov->oldtime = 0;
	return (*fov);
}
