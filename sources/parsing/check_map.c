/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:29:48 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 18:22:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_map(t_cub *cub)
{
	if (ft_line_only_has_whitespaces(cub->line) == true)
		ft_fatal_error_in_parsing(EMPTY_LINE_IN_MAP, cub);
	if (ft_line_has_no_1(cub->line) == true)
		ft_fatal_error_in_parsing(MAP_NOT_CLOSED, cub);
}
