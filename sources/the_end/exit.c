/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/22 17:05:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_exit(t_mlx *mlx_struct)
{
	mlx_destroy_window(mlx_struct->ptr, mlx_struct->win);
	mlx_destroy_display(mlx_struct->ptr);
	free(mlx_struct->ptr);
	free(mlx_struct);
	exit(EXIT_SUCCESS);
	return (0);
}
