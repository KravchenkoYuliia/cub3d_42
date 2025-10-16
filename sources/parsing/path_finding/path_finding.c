/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:50:59 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/13 12:10:43 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_coordinates_of_player(t_cub *cub)
{
	int	i;
	int	line;

	if (!cub || !cub->map.grid)
		return ;
	line = 0;
	while (cub->map.grid[line])
	{
		i = 0;
		while (cub->map.grid[line][i])
		{
			if (ft_strchr("NSEW", cub->map.grid[line][i]) != NULL)
			{
				cub->x_coordinate_of_player = i;
				cub->y_coordinate_of_player = line;
				return ;
			}
			i++;
		}
		line++;
	}
}

static void	ft_try_to_exit_the_map(t_cub *cub, int x, int y)
{
	if (!cub || !cub->map_to_check)
		return ;
	if (y < 0 || x < 0 || (size_t)y >= cub->map_line_counter
		|| (size_t)x >= cub->map_longest_line || !cub->map_to_check[y]
		|| cub->map_to_check[y][x] == OUTSIDE_SPACE
		|| cub->map_to_check[y][x] == '\0')
	{
		if (cub->map_to_check)
			ft_free_char_tab(cub->map_to_check);
		cub->map_to_check = NULL;
		ft_fatal_error_in_parsing(PLAYER_OUT, cub);
	}
	if (cub->map_to_check[y][x] == '1')
		return ;
	if (cub->map_to_check[y][x] == DONE)
		return ;
	if (ft_strchr("0NSWE", cub->map_to_check[y][x]) != NULL)
	{
		cub->map_to_check[y][x] = DONE;
		ft_try_to_exit_the_map(cub, x, y - 1);
		ft_try_to_exit_the_map(cub, x - 1, y);
		ft_try_to_exit_the_map(cub, x + 1, y);
		ft_try_to_exit_the_map(cub, x, y + 1);
	}
}

// TODO: which path are we looking for?
// TODO: not clear the purpose of the function just based on the name
void	ft_path_finding(t_cub *cub)
{
	if (!cub)
		return ;
	ft_coordinates_of_player(cub);
	cub->map_to_check = ft_copy_array_of_char(cub);
	if (!cub->map_to_check)
		ft_fatal_error_in_parsing(NULL, cub);
	ft_try_to_exit_the_map(cub, cub->x_coordinate_of_player,
		cub->y_coordinate_of_player);
	if (cub->map_to_check)
		ft_free_char_tab(cub->map_to_check);
	cub->map_to_check = NULL;
}
