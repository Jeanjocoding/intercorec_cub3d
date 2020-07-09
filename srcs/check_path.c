/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 11:57:10 by tlucille          #+#    #+#             */
/*   Updated: 2020/06/09 11:57:12 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char **g_tex_tab;

int	check_path(char *path, char ***tab)
{
	int ret;

	ret = open(path, O_RDONLY);
	if (ret == -1)
	{
		close(ret);
		custom_freetab(&g_tex_tab);
		error_quit("Error\ninvalid path on one or more textures", tab);
		return (-1);
	}
	else
	{
		close(ret);
		return (1);
	}
}
