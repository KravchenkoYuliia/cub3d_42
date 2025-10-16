/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:26:47 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 15:26:56 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_image(t_mlx *mlx, t_image *image)
{
	if (!image)
		return;
	if (image->img)
		mlx_destroy_image(mlx->ptr, image->img);
	free(image);
}
