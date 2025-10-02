/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 18:14:23 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_paths_to_textures(t_cub *cub)
{
	if (cub->north.path)
		free(cub->north.path);
	if (cub->south.path)
		free(cub->south.path);
	if (cub->east.path)
		free(cub->east.path);
	if (cub->west.path)
		free(cub->west.path);
}

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

void	ft_free_player(t_cub *cub)
{
	if (!cub || !cub->player)
		return ;
	free(cub->player);
	cub->player = NULL;
}

int	ft_free_all_and_exit(t_cub *cub)
{
	if (!cub)
		return (EXIT_FAILURE);
	ft_free_mlx(cub);
	ft_free_player(cub);
	ft_free_paths_to_textures(cub);
	ft_free(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
