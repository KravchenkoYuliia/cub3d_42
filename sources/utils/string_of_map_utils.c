/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_of_map_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:03:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:54:51 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_line_has_no_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			return (false);
		i++;
	}
	return (true);
}

char	**ft_copy_array_of_char(t_cub *cub)
{
	int		line;
	char	**result;

	if (!cub)
		return (NULL);
	line = 0;
	result = ft_calloc(cub->map_line_counter + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (cub->map.grid[line])
	{
		result[line] = ft_strdup(cub->map.grid[line]);
		if (!result[line])
		{
			ft_free_char_tab(result);
			return (NULL);
		}
		line++;
	}
	result[line] = NULL;
	return (result);
}
