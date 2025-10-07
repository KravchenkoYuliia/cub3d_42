/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_outside_spaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 12:21:53 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 15:06:29 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_replace_first_and_last_line(t_cub *cub, int line, int i, bool first)
{
	if (!cub || !cub->map.grid || !cub->map.grid[line]
			|| !cub->map.grid[line][i])
		return ;
	if (cub->map.grid[line][i] == SPACE)
	{
		cub->map.grid[line][i] = OUTSIDE_SPACE;
		if (cub->map.grid[line][i + 1] && cub->map.grid[line][i + 1] == SPACE)
			ft_replace_first_and_last_line(cub, line, i + 1, first);
		if (i > 0 && cub->map.grid[line][i - 1] && cub->map.grid[line][i - 1] == SPACE)
			ft_replace_first_and_last_line(cub, line, i - 1, first);
		if (first == true)
			ft_replace_first_and_last_line(cub, line + 1, i, first);
		else if (first == false && i > 0)
			ft_replace_first_and_last_line(cub, line - 1, i, first);
	}
	ft_replace_first_and_last_line(cub, line, i + 1, first);
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
	ft_replace_sides(cub, 0, 0, true);
	ft_replace_sides(cub, 0, cub->map_longest_line - 1, false);
	ft_replace_first_and_last_line(cub, 0, 0, true);
	ft_replace_first_and_last_line(cub, cub-> map_line_counter - 1, 0, false);
}
