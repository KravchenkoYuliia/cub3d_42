/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:12:16 by jgossard         ###   ########.fr       */
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
	if (!cub || !cub->surface_color)
		return ;
	free(cub->surface_color);
	cub->surface_color = NULL;
}

static void	ft_free_player(t_cub *cub)
{
	if (!cub || !cub->player)
		return ;
	free(cub->player);
	cub->player = NULL;
}

static void	ft_destroy_image(t_cub *cub)
{
	if (!cub || !cub->image)
		return ;
	if (cub->image->img)
		mlx_destroy_image(cub->mlx->ptr, cub->image->img);
	free(cub->image);
	cub->image = NULL;
}

void	ft_free_cub(t_cub *cub)
{
	if (!cub)
		return ;
	ft_destroy_image(cub);
	ft_destroy_textures(cub);
	ft_free_mlx(cub);
	ft_free_map(cub);
	ft_free_paths_to_textures(cub);
	ft_free_colors(cub);
	ft_free_player(cub);
	free(cub);
}
