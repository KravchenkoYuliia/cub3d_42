/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:21:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 14:28:20 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fill_direction_structure(t_cub *cub, int elements_tracker, char **path_to_texture)
{
	if (elements_tracker == TAKEN)
		ft_fatal_error_in_parsing(DOUBLE_ELEMENT, cub);
	*path_to_texture = calloc(ft_strlen(cub->elements_of_line[1])
			+ 1, sizeof(char));
	if (!*path_to_texture)
		ft_fatal_error_in_parsing(NULL, cub);
	ft_strcpy(*path_to_texture, cub->elements_of_line[1]);
}

void	ft_choose_direction_if_texture(t_cub *cub)
{
	if (cub->type == 'N')
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.north, &cub->north.path);
		cub->elements_tracker.north = TAKEN;
	}
	else if (cub->type == 'S')
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.south, &cub->south.path);
		cub->elements_tracker.south = TAKEN;
	}
	else if (cub->type == 'E')
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.east, &cub->east.path);
		cub->elements_tracker.east = TAKEN;
	}
	else if (cub->type == 'W')
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.west, &cub->west.path);
		cub->elements_tracker.west = TAKEN;
	}
}
