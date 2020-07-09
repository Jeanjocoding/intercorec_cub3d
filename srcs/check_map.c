/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:50:42 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:50:44 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char	**g_tex_tab;
extern int	g_alloc_check[5];

int	return_check(int count)
{
	if (count > 0)
		return (1);
	else
		return (0);
}

int	check_first_map(char **line)
{
	int count;
	int i;
	int len;

	i = 0;
	count = 0;
	len = ft_strlen(*line);
	while ((*line)[i])
	{
		if ((*line)[i] == ' ')
			i++;
		else if (i < len && (*line)[i] == '1')
		{
			i++;
			count++;
		}
		else
		{
			custom_freetab(&g_tex_tab);
			return (-1);
		}
	}
	return (return_check(count));
}
