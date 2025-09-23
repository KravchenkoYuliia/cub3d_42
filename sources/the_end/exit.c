/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 19:14:07 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_cub *cub)
{
	mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
	mlx_destroy_display(cub->mlx->ptr);
	free(cub->mlx->ptr);
	free(cub->mlx);
	free(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
