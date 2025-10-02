/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_display_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:14:45 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/01 15:05:51 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_reset_image(t_image *image)
{
	int	total_bytes;

	total_bytes = image->line_len * WIN_HEIGHT;
	ft_memset(image->addr, 0, total_bytes);
}

static void	ft_display_image(t_mlx *mlx, t_image *image)
{
	mlx_put_image_to_window(
		mlx->ptr, mlx->win, image->img, 0, 0);
}

void	ft_render_and_display_image(t_cub *data)
{
	if (!data || !data->mlx || !data->image)
		return ;
	ft_reset_image(data->image);
	// move player
	// draw ceiling
	// draw floor
	ft_raycasting(data);
	ft_display_image(data->mlx, data->image);
}
