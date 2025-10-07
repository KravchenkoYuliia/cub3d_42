/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 09:55:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_paths_to_textures(t_cub *cub)
{
	if (!cub)
		return ;
	if (cub->north.path)
	{	
		free(cub->north.path);
		cub->north.path = NULL;
	}
	if (cub->south.path)
	{
		free(cub->south.path);
		cub->south.path = NULL;
	}
	if (cub->east.path)
	{
		free(cub->east.path);
		cub->east.path = NULL;
	}
	if (cub->west.path)
	{
		free(cub->west.path);
		cub->west.path = NULL;
	}
}

static void	ft_free_colors(t_cub *cub)
{
	int	i;

	i = 0;
	if (!cub)
		return ;
	while (i < NUM_SURFACE && cub->surface_color)
	{

		if (cub->surface_color[i].colors)
		{
			free(cub->surface_color[i].colors);
			cub->surface_color[i].colors = NULL;
		}
		i++;
	}
}

static void	ft_free_mlx(t_cub *cub)
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

static void	ft_free_player(t_cub *cub)
{
	if (!cub || !cub->player)
		return ;
	free(cub->player);
	cub->player = NULL;
}

void	ft_free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	ft_free_mlx(cub);
	ft_free_map(cub);
	ft_free_paths_to_textures(cub);
	ft_free_colors(cub);
	ft_free_player(cub);
	free(cub);
}
