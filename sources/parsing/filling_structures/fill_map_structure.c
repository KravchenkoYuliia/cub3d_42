/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:56:07 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 15:21:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_map_structure(t_cub *cub, char *descriptional_file)
{
	int	i;

	i = 0;
	ft_init_map(cub);
	cub->map_line_counter = 0;
	ft_open_descriptional_file(cub, descriptional_file);
	while (i < cub->map_last_line)
	{
		cub->line = get_next_line(cub->fd);
		if (!cub->line)
			ft_fatal_error_in_parsing(NULL, cub);
		ft_cut_new_line_at_the_end(cub->line);
		if (i + 1 >= cub->map_first_line)
		{
			ft_strcpy(cub->map.grid[cub->map_line_counter], cub->line);
			cub->map_line_counter++;
		}
		free(cub->line);
		i++;
	}
	cub->map.grid[cub->map_line_counter] = NULL;
	ft_read_fd_till_the_end(cub->fd);
	close(cub->fd);
}
