/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_store_texture_path.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:21:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 17:54:54 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_parse_direction_texture_path(t_cub *cub,
	int elements_tracker, char **path_to_texture)
{
	if (elements_tracker == TAKEN)
		ft_fatal_error_in_parsing(DOUBLE_ELEMENT, cub);
	*path_to_texture = ft_calloc(ft_strlen(cub->elements_of_line[1]) + 1,
			sizeof(char));
	if (!*path_to_texture)
		ft_fatal_error_in_parsing(NULL, cub);
	ft_strcpy(*path_to_texture, cub->elements_of_line[1]);
}

static void ft_handle_texture_type(t_cub *cub, int tracker,
	char **path, int *tracker_ptr)
{
	ft_parse_direction_texture_path(cub, tracker, path);
	*tracker_ptr = TAKEN;
}

void ft_parse_and_store_texture_path(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->type == NO)
		ft_handle_texture_type(cub, cub->elements_tracker.north,
			&cub->north.path, &cub->elements_tracker.north);
	else if (cub->type == SO)
		ft_handle_texture_type(cub, cub->elements_tracker.south,
			&cub->south.path, &cub->elements_tracker.south);
	else if (cub->type == EA)
		ft_handle_texture_type(cub, cub->elements_tracker.east,
			&cub->east.path, &cub->elements_tracker.east);
	else if (cub->type == WE)
		ft_handle_texture_type(cub, cub->elements_tracker.west,
			&cub->west.path, &cub->elements_tracker.west);
}
