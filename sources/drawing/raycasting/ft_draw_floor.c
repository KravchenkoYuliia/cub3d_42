/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:17:08 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/02 15:37:28 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_floor(t_image *img, int color)
{
	int	x;
	int	y;

	if (!img || color < 0)
		return ;
	y = WIN_HEIGHT / 2;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ft_draw_pixel(x, y, img, color);
			x++;
		}
		y++;
	}
}
