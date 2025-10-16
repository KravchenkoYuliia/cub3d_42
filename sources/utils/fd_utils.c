/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:09:18 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/13 12:09:12 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: why "descriptional" in the function name? why not just ft_open_file?
void	ft_open_descriptional_file(t_cub *cub, char *file)
{
	cub->fd = -1;
	cub->fd = open(file, O_RDONLY);
	if (cub->fd == -1)
		ft_fatal_error_in_parsing(CANT_OPEN, cub);
}
