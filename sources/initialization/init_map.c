/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:22:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:54:40 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_before_new_reading_of_file(t_cub *cub)
{
	close(cub->fd);
	cub->fd = -1;
	cub->nb_of_line_in_file = cub->line_counter;
}

void	ft_init_map(t_cub *cub)
{
	size_t	i;

	i = 0;
	cub->map.width = cub->map_longest_line;
	cub->map.height = cub->map_line_counter;
	cub->map.grid = ft_calloc(cub->map_line_counter + 1, sizeof(char *));
	if (!cub->map.grid)
		ft_close_program(cub, EXIT_FAILURE);
	while (i < cub->map_line_counter)
	{
		cub->map.grid[i] = ft_calloc(cub->map_longest_line + 1, sizeof(char));
		if (!cub->map.grid[i])
			ft_fatal_error_in_parsing(NULL, cub);
		i++;
	}
}
