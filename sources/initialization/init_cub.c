/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 13:26:19 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture_paths(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	cub->north.path = NULL;
	cub->south.path = NULL;
	cub->east.path = NULL;
	cub->west.path = NULL;
}

static void	ft_init_elements_tracker(t_cub *cub)
{	
	if (!cub)
		exit(EXIT_FAILURE);
	cub->elements_tracker.north = FREE;
	cub->elements_tracker.south = FREE;
	cub->elements_tracker.east = FREE;
	cub->elements_tracker.west = FREE;
	cub->elements_tracker.floor = FREE;
	cub->elements_tracker.ceiling = FREE;
	cub->elements_tracker.map = FREE;
}

static void	ft_init_surface_color(t_cub *cub)
{
	int	i;

	i = 0;
	if (!cub)
		exit(EXIT_FAILURE);
	cub->surface_color = calloc(2, sizeof(t_surface_color));
	//size 2: Floor and Ceiling
	if (!cub->surface_color)
		ft_free_all_and_exit(cub);
	while (i < 2)
	{
		cub->surface_color[i].colors = calloc(3, sizeof(int)); // 3 = RGB
		if (!cub->surface_color[i].colors)
			ft_free_all_and_exit(cub);
		i++;
	}
}

static void	ft_init_map_parsing(t_cub *cub)
{
	cub->line_counter = 0;
	cub->nb_of_line_in_file = 0;
	cub->map_first_line = 0;
	cub->map_line_counter = 0;
	cub->map_longest_line = 0;
	cub->map_is_finished = false;
}

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		exit(EXIT_FAILURE);
	cub->surface_color = NULL;
	ft_init_elements_tracker(cub);
	ft_init_texture_paths(cub);
	ft_init_surface_color(cub);
	ft_init_map_parsing(cub);
	return (cub);
}
