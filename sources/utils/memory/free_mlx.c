/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:21:48 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 15:22:03 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_mlx(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->mlx)
	{
		if (cub->mlx->win && cub->mlx->ptr)
		{
			mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
			cub->mlx->win = NULL;
		}
		if (cub->mlx->ptr)
		{
			mlx_destroy_display(cub->mlx->ptr);
			free(cub->mlx->ptr);
			cub->mlx->ptr = NULL;
		}
		free(cub->mlx);
		cub->mlx = NULL;
	}
}
