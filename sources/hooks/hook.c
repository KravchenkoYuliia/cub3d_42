/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:28 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 16:30:10 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == ESC_BUTTON)
		ft_exit(cub);
	return (0);
}

void	ft_hook(t_cub *cub)
{
	mlx_hook(cub->mlx->win, KeyPress, KeyPressMask,
		&ft_key_press, cub);
	mlx_hook(cub->mlx->win, DestroyNotify, KeyPressMask,
		&ft_exit, cub);
}
