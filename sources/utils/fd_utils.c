/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:09:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 12:10:41 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_open_descriptional_file(t_cub *cub, char *file)
{
	cub->fd = -1;
	cub->fd = open(file, O_RDONLY);
	if (cub->fd == -1)
		ft_fatal_error_in_parsing(CANT_OPEN, cub);
}
