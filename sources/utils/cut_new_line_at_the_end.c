/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_new_line_at_the_end.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:07:24 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/29 17:10:58 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cut_new_line_at_the_end(t_cub *cub)
{
	int	last_index;

	last_index = ft_strlen(cub->line) - 1;
	if (last_index > 0 && cub->line[last_index])
		cub->line[last_index] = '\0';
}
