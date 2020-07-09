/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:57:10 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:57:12 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_screenheight;
extern int	g_screenwidth;
extern int	g_alloc_check[5];
int		g_n_set;
int		g_so_set;
int		g_e_set;
int		g_w_set;
int		g_sp_set;

int		get_south(char ***tab)
{
	static int duplicate;

	if (duplicate > 0)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nduplicate south texture format", tab);
	}
	if (ft_tablen(*tab) != 2)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nInvalid south texture format", tab);
	}
	check_path((*tab)[1], tab);
	if (!(add_tex_num((*tab)[1], 0)))
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nmalloc error", tab);
	}
	g_alloc_check[0] = 1;
	ft_freetab(tab);
	duplicate++;
	g_so_set = 2;
	return (0);
}

int		get_north(char ***tab)
{
	static int duplicate;

	if (duplicate > 0)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nduplicate north texture format", tab);
	}
	if (ft_tablen(*tab) != 2)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nInvalid north texture format", tab);
	}
	check_path((*tab)[1], tab);
	if (!(add_tex_num((*tab)[1], 1)))
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nmalloc error", tab);
	}
	ft_freetab(tab);
	g_alloc_check[1] = 1;
	duplicate++;
	g_n_set = 2;
	return (0);
}

int		get_west(char ***tab)
{
	static int duplicate;

	if (duplicate > 0)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nduplicate west texture format", tab);
	}
	if (ft_tablen(*tab) != 2)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nInvalid west texture format", tab);
	}
	check_path((*tab)[1], tab);
	if (!(add_tex_num((*tab)[1], 2)))
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nmalloc error", tab);
	}
	ft_freetab(tab);
	g_alloc_check[2] = 1;
	duplicate++;
	g_w_set = 2;
	return (0);
}

int		get_east(char ***tab)
{
	static int duplicate;

	if (duplicate > 0)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nduplicate east texture format", tab);
	}
	if (ft_tablen(*tab) != 2)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nInvalid east texture format", tab);
	}
	check_path((*tab)[1], tab);
	if (!(add_tex_num((*tab)[1], 3)))
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nmalloc error", tab);
	}
	ft_freetab(tab);
	g_alloc_check[3] = 1;
	duplicate++;
	g_e_set = 2;
	return (0);
}

int		get_sprite(char ***tab)
{
	static int duplicate;

	if (duplicate > 0)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nduplicate sprite texture format", tab);
	}
	if (ft_tablen(*tab) != 2)
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nInvalid sprite texture format", tab);
	}
	check_path((*tab)[1], tab);
	if (!(add_tex_num((*tab)[1], 4)))
	{
		custom_freetab(&g_tex_tab);
		error_quit("Error\nmalloc error", tab);
	}
	ft_freetab(tab);
	g_alloc_check[4] = 1;
	duplicate++;
	g_sp_set = 2;
	return (0);
}
