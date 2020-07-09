/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_get_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:51:29 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:51:31 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_screenheight;
extern int	g_screenwidth;
extern int	**g_worldmap;
extern void	*g_mlx_ptr;
int		g_res_set;

int		check_all_digit(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			return (-1);
		str++;
	}
	return (1);
}

int		error_quit(char *msg, char ***tab)
{
	ft_printf("%s\n", msg);
	if (tab != NULL)
		ft_freetab(tab);
	exit(1);
	return (1);
}

int		check_res_dup(void)
{
	static int duplicate;

	duplicate++;
	return (duplicate);
}

int		get_res(char ***tab)
{
	int sizex;
	int sizey;

	sizex = 0;
	sizey = 0;
	if (check_all_digit((*tab)[1]) == -1
		|| check_all_digit((*tab)[2]) == -1
		|| ft_tablen(*tab) != 3
		|| check_res_dup() > 1)
	{
		custom_freetab(&g_tex_tab);
		error_quit("error: wrong or duplicate resolution format", tab);
	}
	mlx_get_screen_size(g_mlx_ptr, &sizex, &sizey);
	g_screenwidth = ft_atoi((*tab)[1]);
	g_screenheight = ft_atoi((*tab)[2]);
	if (g_screenwidth > sizex)
		g_screenwidth = sizex;
	if (g_screenheight > sizey)
		g_screenheight = sizey;
	ft_freetab(tab);
	g_res_set = 2;
	return (1);
}
