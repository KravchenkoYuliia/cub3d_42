/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 16:28:39 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line_only_has_valid_char(t_cub *cub)
{
	int		i;

	i = 0;
	while (cub->line[i])
	{
		if (ft_strchr("NSEW", cub->line[i]) != NULL)
			cub->nb_of_players++;
		if (cub->nb_of_players < 1)
			ft_fatal_error_in_parsing(ONE_PLAYER, cub);
		if (ft_strchr("01 NSEW", cub->line[i]) == NULL)
		{
			printf("Char '%c'[ascii: %d] found in map\n",
				cub->line[i], cub->line[i]);
			ft_fatal_error_in_parsing(INVALID_CHAR_IN_MAP, cub);
		}
		i++;
	}
}

void	ft_check_map(t_cub *cub)
{
	if (ft_line_has_no_1(cub->line) == true)
		ft_fatal_error_in_parsing(INVALID_MAP, cub);
	if (cub->map_is_finished == true)
		ft_fatal_error_in_parsing(EMPTY_LINE_IN_MAP, cub);
	ft_check_line_only_has_valid_char(cub);
}
