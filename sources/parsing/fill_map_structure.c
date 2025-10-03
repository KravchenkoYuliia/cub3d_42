/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:56:07 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 13:18:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_put_line_to_map_grid(t_cub *cub)
{
	(void)cub;
}

void	ft_fill_map_structure(t_cub *cub, char *descriptional_file)
{
	int	i;

	i = 0;
	ft_init_map(cub);
	cub->line_counter = 0;
	ft_open_descriptional_file(cub, descriptional_file);
	while (i < cub->nb_of_line_in_file)
	{
		cub->line = get_next_line(cub->fd);
		if (!cub->line)
			ft_fatal_error_in_parsing(NULL, cub);
		cub->line_counter++;
		if (cub->line_counter >= cub->map_first_line)
			ft_put_line_to_map_grid(cub);
		free(cub->line);
		i++;
	}
	close(cub->fd);
}
