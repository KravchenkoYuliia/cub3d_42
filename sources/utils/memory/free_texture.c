/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:18:46 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 15:31:22 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_destroy_textures(t_cub *cub)
{
	if (!cub || !cub->mlx)
		return ;
	if (cub->north.img)
		mlx_destroy_image(cub->mlx->ptr, cub->north.img);
	if (cub->south.img)
		mlx_destroy_image(cub->mlx->ptr, cub->south.img);
	if (cub->east.img)
		mlx_destroy_image(cub->mlx->ptr, cub->east.img);
	if (cub->west.img)
		mlx_destroy_image(cub->mlx->ptr, cub->west.img);
}
