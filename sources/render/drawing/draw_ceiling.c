/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:15:45 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 17:42:26 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_draw_ceiling(t_image *img, int color)
{
	int	x;
	int	y;

	if (!img || color < 0)
		return (false);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			ft_draw_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
	return (true);
}
