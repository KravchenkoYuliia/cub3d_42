/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:22:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 12:44:53 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_cub *cub)
{
	size_t	i;

	i = 0;
	cub->map.width = cub->map_longest_line;
	cub->map.height = cub->map_line_counter;
	cub->map.grid = calloc(cub->map_line_counter + 1, sizeof(char *));
	if (!cub->map.grid)
		ft_free_all_and_exit(cub);
	while (i < cub->map_line_counter)
	{
		cub->map.grid[i] = calloc(cub->map_longest_line + 1, sizeof(char));
		if (!cub->map.grid[i])
			ft_fatal_error_in_parsing(NULL, cub);
		i++;
	}

}
