/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 16:15:40 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_all(t_cub *cub)
{
	if (cub && cub->mlx && cub->mlx->ptr)
		free(cub->mlx->ptr);
	if (cub && cub->mlx)
		free(cub->mlx);
	if (cub && cub->texture)
		free(cub->texture);
	if (cub)
		free(cub);
}

int	ft_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
	mlx_destroy_display(cub->mlx->ptr);
	ft_free_all(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
