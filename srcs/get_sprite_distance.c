/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprite_distance.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:54:55 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:54:56 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_sprites	*get_sprite_distance(t_sprites *sprite, t_fov *fov)
{
	t_sprites	*first;

	first = sprite->first;
	while (sprite != NULL)
	{
		sprite->distance = (fov->posx - sprite->x) *
			(fov->posx - sprite->x) + (fov->posy - sprite->y) *
			(fov->posy - sprite->y);
		sprite = sprite->next;
	}
	return (first);
}
