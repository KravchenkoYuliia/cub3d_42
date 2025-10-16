/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:00:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:11:07 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_init_mlx(t_cub *cub)
{
	if (!cub)
		return (false);
	cub->mlx = ft_calloc(1, sizeof(t_mlx));
	if (!cub->mlx)
		return (false);
	cub->mlx->ptr = mlx_init();
	if (!cub->mlx->ptr)
		return (ft_free_mlx(cub), false);
	cub->mlx->win = mlx_new_window(cub->mlx->ptr,
			WIN_WIDTH,
			WIN_HEIGHT,
			WIN_NAME);
	if (!cub->mlx->win)
		return (ft_free_mlx(cub), false);
	cub->image = ft_init_image(cub->mlx,
			WIN_WIDTH,
			WIN_HEIGHT);
	if (!cub->image)
		return (ft_free_mlx(cub), false);
	return (true);
}
