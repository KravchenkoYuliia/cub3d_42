/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/30 16:51:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_nodoubles_values(t_cub *cub)
{
	cub->no_doubles.north = FREE;
	cub->no_doubles.south = FREE;
	cub->no_doubles.east = FREE;
	cub->no_doubles.west = FREE;
	cub->no_doubles.floor = FREE;
	cub->no_doubles.ceiling = FREE;
}

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		exit(EXIT_FAILURE);
	cub->surface_color = NULL;
	ft_init_nodoubles_values(cub);
	return (cub);
}
