/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:56:38 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 19:15:27 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_win(t_cub *cub)
{
	cub->mlx = calloc(1, sizeof(t_mlx));
	if (!cub->mlx)
		exit(EXIT_FAILURE);
	cub->mlx->ptr = mlx_init();
	if (!cub->mlx->ptr)
	{
		free(cub->mlx);
		free(cub);
		exit(EXIT_FAILURE);
	}
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,
			WIN_WIDTH, WIN_HEIGHT, "YO");
	if (!cub->mlx->win)
	{
		free(cub->mlx->ptr);
		free(cub->mlx);
		free(cub);
		exit(EXIT_FAILURE);
	}
	ft_hook(cub);
	mlx_loop(cub->mlx->ptr);
}
