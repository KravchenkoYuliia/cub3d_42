/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 14:44:53 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_init_texture_paths(t_cub *cub)
{
	if (!cub)
		return (false);
	cub->north.path = NULL;
	cub->south.path = NULL;
	cub->east.path = NULL;
	cub->west.path = NULL;
	return (true);
}

static bool	ft_init_elements_tracker(t_cub *cub)
{
	if (!cub)
		return (false);
	cub->elements_tracker.north = FREE;
	cub->elements_tracker.south = FREE;
	cub->elements_tracker.east = FREE;
	cub->elements_tracker.west = FREE;
	cub->elements_tracker.floor = FREE;
	cub->elements_tracker.ceiling = FREE;
	cub->elements_tracker.map = FREE;
	return (true);
}

bool	ft_init_surface_color(t_cub *cub)
{
	int	i;

	if (!cub)
		return (false);
	cub->surface_color = malloc(NUM_SURFACES * sizeof(t_surface_color));
	if (!cub->surface_color)
		return (false);
	i = 0;
	while (i < NUM_SURFACES)
	{
		cub->surface_color[i].surface_type = i;
		cub->surface_color[i].color = 0;
		i++;
	}
	return (true);
}

static bool	ft_init_map_parsing(t_cub *cub)
{
	if (!cub)
		return (false);
	cub->line_counter = 0;
	cub->map_flag = false;
	cub->line = NULL;
	cub->nb_of_line_in_file = 0;
	cub->map_first_line = 0;
	cub->map_last_line = 0;
	cub->map_line_counter = 0;
	cub->map_longest_line = 0;
	cub->map_is_finished = false;
	cub->nb_of_players = 0;
	cub->x_coordinate_of_player = 0;
	cub->y_coordinate_of_player = 0;
	return (true);
}

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		return (NULL);
	cub->surface_color = NULL;
	if (!ft_init_elements_tracker(cub)
		|| !ft_init_texture_paths(cub)
		|| !ft_init_surface_color(cub)
		|| !ft_init_map_parsing(cub))
		return (ft_free_cub(cub), NULL);
	return (cub);
}
