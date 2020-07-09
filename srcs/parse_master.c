/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_master.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:57:02 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:57:04 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_screenheight;
extern int	g_screenwidth;
extern int	**g_worldmap;
extern int	g_mlen;
extern int	g_mheight;
int		g_alloc_check[5];
extern int	g_res_set;
extern int	g_n_set;
extern int	g_so_set;
extern int	g_e_set;
extern int	g_w_set;
extern int	g_sp_set;
extern int	g_f_set;
extern int	g_c_set;
int		g_invalid_line;

int		func_utils(char ***tab)
{
	if ((*tab)[0] == NULL || (*tab)[0][0] == '\0')
	{
		g_invalid_line = 2;
		return (-2);
	}
	if (ft_strcmp((*tab)[0], "R") == 0)
		return (get_res(tab));
	if (ft_strcmp((*tab)[0], "NO") == 0)
		return (get_north(tab));
	if (ft_strcmp((*tab)[0], "SO") == 0)
		return (get_south(tab));
	if (ft_strcmp((*tab)[0], "WE") == 0)
		return (get_west(tab));
	if (ft_strcmp((*tab)[0], "EA") == 0)
		return (get_east(tab));
	if (ft_strcmp((*tab)[0], "S") == 0)
		return (get_sprite(tab));
	if (ft_strcmp((*tab)[0], "F") == 0)
		return (get_floor(tab));
	if (ft_strcmp((*tab)[0], "C") == 0)
		return (get_g_ceiling(tab));
	return (-2);
}

void	check_res(char ***full_tab)
{
	if (g_res_set != 2 || g_n_set != 2 || g_so_set != 2 || g_sp_set != 2
		|| g_w_set != 2 || g_e_set != 2 || g_f_set != 2
		|| g_c_set != 2 || g_c_set != 2 || g_invalid_line == 2)
		ft_freetab(full_tab);
	if (g_invalid_line == 2)
		error_quit("Error\ninvalid line in configuration file", NULL);
	if (g_res_set != 2)
		error_quit("Error\nresolution size not set", NULL);
	if (g_n_set != 2)
		error_quit("Error\nnorth texture not set", NULL);
	if (g_so_set != 2)
		error_quit("Error\nsouth texture not set", NULL);
	if (g_sp_set != 2)
		error_quit("Error\nsprite texture not set", NULL);
	if (g_e_set != 2)
		error_quit("Error\neast texture not set", NULL);
	if (g_w_set != 2)
		error_quit("Error\nwest texture not set", NULL);
	if (g_f_set != 2)
		error_quit("Error\nfloor color not set", NULL);
	if (g_c_set != 2)
		error_quit("Error\nceiling color not set", NULL);
}

int		get_right_func(char **line, char ***full_tab, int i, t_fov *fov)
{
	char	**tab;
	int		ret;
	int		ret2;

	if (*line == NULL || (*line)[0] == '\0'
		|| (ft_strlen(*line) == 1 && (*line)[0] == ' '))
		return (0);
	if (!(tab = ft_split(*line, ' ')))
		return (-1);
	if ((ret = func_utils(&tab)) != -2)
		return (ret);
	if ((ret2 = check_first_map(line)) == 1)
	{
		ft_freetab(&tab);
		check_res(full_tab);
		return (set_map(*full_tab, i, fov));
	}
	if (ret2 == -1)
	{
		ft_freetab(&tab);
		ft_freetab(full_tab);
		error_quit("Error\nsyntax error detected in configuration file", NULL);
	}
	ft_freetab(&tab);
	return (0);
}

void	allocarray_set(int dst[5], int nbr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		dst[i] = nbr;
		i++;
	}
}

int		parse_master(int fd, t_fov *fov)
{
	int		ret;
	int		i;
	int		tablen;
	char	**tab;

	if (!(tab = get_cub_tab(fd)))
		return (-1);
	allocarray_set(g_alloc_check, 0, 5);
	tablen = ft_tablen(tab);
	if (tablen == 0)
		error_quit("Error\nempty or invalid file", NULL);
	i = -1;
	while (++i < tablen)
	{
		ret = get_right_func(&(tab[i]), &tab, i, fov);
		if (ret == -1)
			free_tab_ret(&tab);
		if (ret == 3)
		{
			ft_freetab(&tab);
			return (1);
		}
	}
	ft_freetab(&tab);
	return (1);
}
