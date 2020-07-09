/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:53:02 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:53:03 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int		**g_worldmap;
extern int		**g_textures;
extern double	*g_zbuffer;
extern char		**g_tex_tab;
extern int		g_mlen;
extern t_data	g_tex_list;

void	free_sprites(t_sprites *sprites)
{
	t_sprites	*temp;

	while (sprites->prev != NULL)
		sprites = sprites->prev;
	while (sprites->next != NULL)
	{
		temp = sprites->next;
		free(sprites);
		sprites = NULL;
		sprites = temp;
	}
	free(sprites);
	sprites = NULL;
}
