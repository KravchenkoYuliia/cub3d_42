/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces_in_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:26:06 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 11:39:37 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_make_map_rectangular(t_cub *cub)
{
	int 	line;
	size_t	line_len;

	if (!cub)
		return ;
	line = 0;
	while (cub->map.grid && cub->map.grid[line])	
	{
		line_len = ft_strlen(cub->map.grid[line]);
		if (line_len < cub->map_longest_line)
		{
			while ((line_len < cub->map_longest_line))
			{
				cub->map.grid[line][line_len] = SPACE;
				line_len++;
			}
			cub->map.grid[line][line_len] = '\0';
		}
		line++;
	}
}

/*static void	ft_replace_outside_spaces(t_cub *cub)
{
}*/

void	ft_handle_spaces_in_map(t_cub *cub)
{
	ft_make_map_rectangular(cub);
	//ft_replace_outside_spaces(cub);
}
