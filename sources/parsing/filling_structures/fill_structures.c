/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:21:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 18:21:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fill_direction_structure(t_cub *cub,
		int elements_tracker, char **path_to_texture)
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
	if (cub->type == NO)
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.north,
			&cub->north.path);
		cub->elements_tracker.north = TAKEN;
	}
	else if (cub->type == SO)
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.south,
			&cub->south.path);
		cub->elements_tracker.south = TAKEN;
	}
	else if (cub->type == EA)
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.east,
			&cub->east.path);
		cub->elements_tracker.east = TAKEN;
	}
	else if (cub->type == WE)
	{
		ft_fill_direction_structure(cub, cub->elements_tracker.west,
			&cub->west.path);
		cub->elements_tracker.west = TAKEN;
	}
}

static void	ft_fill_color_structure(t_cub *cub,
		int elements_tracker, int *colors)
{
	int		i;
	char	**numbers;

	if (elements_tracker == TAKEN)
		ft_fatal_error_in_parsing(DOUBLE_ELEMENT, cub);
	i = 0;
	numbers = ft_split(cub->elements_of_line[1], ',');
	if (!numbers)
		ft_fatal_error_in_parsing(DOUBLE_ELEMENT, cub); //123,123,123
	while (i < 3)
	{
		colors[i] = ft_atoi(numbers[i]);
		i++;
	}
	ft_free_char_tab(numbers);
}

void	ft_choose_surface_if_color(t_cub *cub)
{
	if (cub->type == F)
	{
		ft_fill_color_structure(cub, cub->elements_tracker.floor,
			cub->surface_color[0].colors);
		cub->elements_tracker.floor = TAKEN;
	}
	else if (cub->type == C)
	{
		ft_fill_color_structure(cub, cub->elements_tracker.ceiling,
			cub->surface_color[1].colors);
		cub->elements_tracker.ceiling = TAKEN;
	}
}
