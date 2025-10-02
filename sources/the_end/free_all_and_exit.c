/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 17:12:52 by yukravch         ###   ########.fr       */
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

static void	ft_free_colors(t_cub *cub)
{
	if (cub->surface_color)
	{
		if (cub->surface_color[0].colors)
			free(cub->surface_color[0].colors);
		if (cub->surface_color[1].colors)
			free(cub->surface_color[1].colors);
		free(cub->surface_color);
	}
}

int	ft_free_all_and_exit(t_cub *cub)
{
	if (cub)
	{
		if (cub->mlx)
		{
			if (cub->mlx->ptr)
			{
				if (cub->mlx->win)
					mlx_destroy_window(cub->mlx->ptr, cub->mlx->win);
				mlx_destroy_display(cub->mlx->ptr);
				free(cub->mlx->ptr);
			}
			free(cub->mlx);
		}
		ft_free_paths_to_textures(cub);
		ft_free_colors(cub);
		free(cub);
	}
	exit(EXIT_SUCCESS);
	return (0);
}
