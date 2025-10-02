/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_ceiling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:15:45 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/01 15:19:26 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_ceiling(t_img *img, int color)
{
	int	x;
	int	y;

	if (!img || color < 0)
		return ;
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			ft_draw_pixel(x, y, img, color);
			y++;
		}
		x++;
	}
}
