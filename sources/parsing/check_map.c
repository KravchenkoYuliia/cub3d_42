/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 18:55:35 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line_only_has_valid_char(t_cub *cub)
{
	int		i;
	char	*valid_chars;

	i = 0;
	valid_chars = calloc(8, sizeof(char));
	//7 valid char: 1, 0, N, S, E, W, space + NULL
	if (!valid_chars)
		ft_fatal_error_in_parsing(MAP_NOT_CLOSED, cub);
	ft_strcpy(valid_chars, "01 NSEW");
	while (cub->line[i])
	{
		if (ft_strchr(valid_chars, cub->line[i]) == NULL)
		{
			free(valid_chars);
			printf("Char [%c][%d] found in map\n", cub->line[i], cub->line[i]);
			ft_fatal_error_in_parsing(INVALID_CHAR_IN_MAP, cub);
		}
		i++;
	}
	free(valid_chars);
}

void	ft_check_map(t_cub *cub)
{
	if (ft_line_only_has_whitespaces(cub->line) == true)
		ft_fatal_error_in_parsing(EMPTY_LINE_IN_MAP, cub);
	if (ft_line_has_no_1(cub->line) == true)
		ft_fatal_error_in_parsing(MAP_NOT_CLOSED, cub);
	ft_check_line_only_has_valid_char(cub);
}
