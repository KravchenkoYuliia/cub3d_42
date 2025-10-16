/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:04:32 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/16 14:10:56 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image	*ft_init_image(t_mlx *mlx, int width, int height)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (NULL);
	image->img = mlx_new_image(mlx->ptr, width, height);
	if (!image->img)
		return (ft_free_image(mlx, image), NULL);
	image->addr = mlx_get_data_addr(image->img,
			&image->bpp,
			&image->line_len,
			&image->endian);
	if (!image->addr)
		return (ft_free_image(mlx, image), NULL);
	return (image);
}
