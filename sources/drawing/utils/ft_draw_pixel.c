/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:57:03 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/01 15:00:53 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_WIDTH || y > WIN_HEIGHT || x < 0 || y < 0)
		return ;
	dst = image->addr + ((y * image->line_len) + (x * (image->bpp / 8)));
	*(unsigned int *)(dst) = color;
}

