/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_structures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 14:03:15 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 18:56:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_elements_tracker(t_cub *cub, int elements_tracker[7])
{
	elements_tracker[0] = cub->elements_tracker.north;
	elements_tracker[1] = cub->elements_tracker.south;
	elements_tracker[2] = cub->elements_tracker.east;
	elements_tracker[3] = cub->elements_tracker.west;
	elements_tracker[4] = cub->elements_tracker.floor;
	elements_tracker[5] = cub->elements_tracker.ceiling;
	elements_tracker[6] = cub->elements_tracker.map;
}

void	ft_check_if_all_elements_are_in_file(t_cub *cub)
{
	int	i;
	int	elements_tracker[7];

	i = 0;
	ft_fill_elements_tracker(cub, elements_tracker);
	while (i < 7)
	{
		//there are 7 elements in the map(4 directions, 2 colors, 1 map)
		if (elements_tracker[i] != TAKEN)
		{
			write(STDERR_FILENO, ELEMENT_MISSING, ft_strlen(ELEMENT_MISSING));
			ft_free_all_and_exit(cub);
		}
		i++;
	}
}
