/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:56:38 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/22 17:45:46 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_win(void)
{
	t_mlx	*mlx_struct;

	mlx_struct = calloc(1, sizeof(t_mlx));
	if (!mlx_struct)
		exit(EXIT_FAILURE);
	mlx_struct->ptr = mlx_init();
	if (!mlx_struct->ptr)
	{
		free(mlx_struct);
		exit(EXIT_FAILURE);
	}
	mlx_struct->win = mlx_new_window(mlx_struct->ptr,
			WIN_WIDTH, WIN_HEIGHT, "YO");
	if (!mlx_struct->win)
	{
		free(mlx_struct->ptr);
		free(mlx_struct);
		exit(EXIT_FAILURE);
	}
	ft_hook(mlx_struct);
	mlx_loop(mlx_struct->ptr);
}
