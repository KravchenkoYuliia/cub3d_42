/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:00:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 16:00:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_mlx(t_cub *cub)
{
	cub->mlx = calloc(1, sizeof(t_mlx));
	if (!cub->mlx)
	{
		free(cub->texture);
		free(cub);
		exit(EXIT_FAILURE);
	}
	cub->mlx->ptr = mlx_init();
	if (!cub->mlx->ptr)
	{
		free(cub->mlx);
		free(cub->texture);
		free(cub);
		exit(EXIT_FAILURE);
	}
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,
			WIN_WIDTH, WIN_HEIGHT, "YO");
	if (!cub->mlx->win)
	{
		free(cub->mlx->ptr);
		free(cub->mlx);
		free(cub->texture);
		free(cub);
		exit(EXIT_FAILURE);
	}
	ft_hook(cub);
	mlx_loop(cub->mlx->ptr);
}
