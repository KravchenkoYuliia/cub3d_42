/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 12:06:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_all_and_exit(t_cub *cub)
{
	if (cub)
	{
		if (cub->mlx)
		{
			if (cub->mlx->ptr)
			{
				if (cub->mlx->win)
					mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
				mlx_destroy_display(cub->mlx->ptr);
				free(cub->mlx->ptr);
			}
			free(cub->mlx);
		}
		if (cub->texture)
			free(cub->texture);
		free(cub);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
