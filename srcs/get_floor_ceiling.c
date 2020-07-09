/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:53:44 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:53:46 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int	g_ground;
extern int	g_ceiling;
int		g_f_set;
int		g_c_set;

int		get_rgb(int r, int g, int b)
{
	int rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

int		check_floor_dup(void)
{
	static int duplicate;

	duplicate++;
	return (duplicate);
}

int		check_ceil_dup(void)
{
	static int duplicate;

	duplicate++;
	return (duplicate);
}

int		get_floor(char ***tab)
{
	int		r;
	int		g;
	int		b;
	char	**tab2;

	if (ft_tablen(*tab) != 2)
		error_quit("Error\ninvalid floor format", tab);
	if (!(tab2 = ft_split((*tab)[1], ',')))
		return (-1);
	if (check_all_digit(tab2[0]) == -1
		|| check_all_digit(tab2[1]) == -1
		|| check_all_digit(tab2[2]) == -1
		|| check_floor_dup() > 1)
		error_quit("Error\nwrong or duplicate floor format", tab);
	ft_freetab(tab);
	r = ft_atoi(tab2[0]);
	g = ft_atoi(tab2[1]);
	b = ft_atoi(tab2[2]);
	g_ground = get_rgb(r, g, b);
	ft_freetab(&tab2);
	g_f_set = 2;
	return (1);
}

int		get_g_ceiling(char ***tab)
{
	int		r;
	int		g;
	int		b;
	char	**tab2;

	if (ft_tablen(*tab) != 2)
		error_quit("Error\ninvalid ceiling format", tab);
	if (!(tab2 = ft_split((*tab)[1], ',')))
		return (-1);
	if (check_all_digit(tab2[0]) == -1
		|| check_all_digit(tab2[1]) == -1
		|| check_all_digit(tab2[2]) == -1
		|| check_ceil_dup() > 1)
		error_quit("Error\nwrong or duplicate ceiling format", tab);
	ft_freetab(tab);
	r = ft_atoi(tab2[0]);
	g = ft_atoi(tab2[1]);
	b = ft_atoi(tab2[2]);
	g_ceiling = get_rgb(r, g, b);
	ft_freetab(&tab2);
	g_c_set = 2;
	return (1);
}
