/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 17:01:56 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture_paths(t_cub *cub)
{
	cub->north.path = NULL;
	cub->south.path = NULL;
	cub->east.path = NULL;
	cub->west.path = NULL;
}

static void	ft_init_elements_tracker(t_cub *cub)
{
	cub->elements_tracker.north = FREE;
	cub->elements_tracker.south = FREE;
	cub->elements_tracker.east = FREE;
	cub->elements_tracker.west = FREE;
	cub->elements_tracker.floor = FREE;
	cub->elements_tracker.ceiling = FREE;
	cub->elements_tracker.map = FREE;
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
	return (cub);
}
