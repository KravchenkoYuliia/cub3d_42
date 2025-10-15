/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:08:27 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/10 11:26:47 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_init_texture_image(t_mlx *mlx, t_texture *texture)
{
	if (!mlx || !texture || !texture->path)
		return (false);
	texture->img = mlx_xpm_file_to_image(mlx->ptr,
			texture->path,
			&texture->width,
			&texture->height);
	if (!texture->img)
	{
		write(STDERR_FILENO, ERR_TEXTURE_LOAD, ft_strlen(ERR_TEXTURE_LOAD));
		return (false);
	}
	texture->addr = mlx_get_data_addr(texture->img,
			&texture->bpp,
			&texture->line_len,
			&texture->endian);
	if (!texture->addr)
	{
		write(STDERR_FILENO, ERR_TEXTURE_ADDR, ft_strlen(ERR_TEXTURE_ADDR));
		return (false);
	}
	return (true);
}
