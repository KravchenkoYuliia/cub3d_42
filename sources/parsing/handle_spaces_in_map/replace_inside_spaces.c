/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_inside_spaces.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:42:21 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 15:46:44 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_replace_inside_spaces(t_cub *cub)
{
	int	i;
	int	line;

	if (!cub || !cub->map.grid)
		return ;
	line = 0;
	while (cub->map.grid[line])
	{
		i = 0;
		while (cub->map.grid[line] && cub->map.grid[line][i])
		{
			if (cub->map.grid[line][i] == SPACE)
				cub->map.grid[line][i] = '0';
			i++;
		}
		line++;
	}
}
