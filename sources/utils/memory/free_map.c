/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:13:40 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/06 11:47:15 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(t_cub *cub)
{
	size_t	i;

	i = 0;
	if (cub->map.grid)
	{
		while (i < cub->map_line_counter && cub->map.grid[i])
		{
			free(cub->map.grid[i]);
			i++;
		}
		free(cub->map.grid);
	}
}
