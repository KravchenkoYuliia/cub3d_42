/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:28 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/22 17:45:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int keycode, t_mlx *mlx_struct)
{
	if (keycode == ESC_BUTTON)
		ft_exit(mlx_struct);
	return (0);
}

void	ft_hook(t_mlx *mlx_struct)
{
	mlx_hook(mlx_struct->win, KeyPress, KeyPressMask,
		&ft_key_press, mlx_struct);
	mlx_hook(mlx_struct->win, DestroyNotify, KeyPressMask,
		&ft_exit, mlx_struct);
}
