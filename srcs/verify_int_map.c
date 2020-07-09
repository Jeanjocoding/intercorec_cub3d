/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_int_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:58:32 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:58:34 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char **g_tex_tab;
extern int g_pos_check;

int		free_all_invalid_map(int ***map, int g_mlen)
{
	free_int_tab(map, g_mlen);
	ft_freetab(&g_tex_tab);
	error_quit("Error\ninvalid map", NULL);
	return (-1);
}

int		check_fov_char(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		verify_int_map(int ***map, int g_mlen, int g_mheight)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < g_mheight)
	{
		while (x < g_mlen)
		{
			if ((*map)[x][y] == 0 || check_fov_char((*map)[x][y]) == 1
				|| (*map)[x][y] == 2)
			{
				if (x == 0 || x >= g_mlen - 1 || (*map)[x - 1][y] == -6
					|| (*map)[x + 1][y] == -6 || y == 0 || y >= g_mheight - 1
					|| (*map)[x][y + 1] == -6 || (*map)[x][y - 1] == -6)
					free_all_invalid_map(map, g_mlen);
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (g_pos_check == 0)
		free_all_invalid_map(map, g_mlen);
	return (1);
}
