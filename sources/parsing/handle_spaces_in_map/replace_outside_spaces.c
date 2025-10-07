/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_outside_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:21:53 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 14:30:55 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_replace_first_line(t_cub *cub)
{
	int	i;
	int	line;

	if (!cub)
		return ;
	i = 0;
	line = 0;
	while (cub->map.grid && cub->map.grid[line] && cub->map.grid[line][i]
			&& cub->map.grid[line][i] == SPACE)
	{
		line = 0;
		cub->map.grid[line][i] = OUTSIDE_SPACE;
		while (cub->map.grid && cub->map.grid[line + 1]
			&& cub->map.grid[line + 1][i] == SPACE)
		{
			cub->map.grid[line + 1][i] = OUTSIDE_SPACE;
			line++;
		}
		i++;
	}
}

static void	ft_replace_sides(t_cub *cub, int line, int i, bool start)
{
	if (!cub || !cub->map.grid || !cub->map.grid[line]
		|| !cub->map.grid[line][i])
		return ;
	if (cub->map.grid[line][i] == SPACE)
	{
		cub->map.grid[line][i] = OUTSIDE_SPACE;
		if (start == true)
			ft_replace_sides(cub, line, i + 1, start);
		else if (start == false && i > 0)
			ft_replace_sides(cub, line, i - 1, start);
	}
	if (start == true)
		i = 0;
	else
		i = cub->map_longest_line - 1;
	if (cub->map.grid[line + 1])
		ft_replace_sides(cub, line + 1, i, start);
}

void	ft_replace_outside_spaces(t_cub *cub)
{
	if (!cub)
		return ;
	ft_replace_sides(cub, 0, 0, true); //from left to right
	ft_replace_sides(cub, 0, cub->map_longest_line - 1, false);
	//from right to left
	ft_replace_first_line(cub);
	//ft_replace_last_line(cub);
}
