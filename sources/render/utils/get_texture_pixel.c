/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_pixel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:02:00 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/13 14:44:22 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_get_texture_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;
	int		color;
	int		bytes_per_pixel;

	if (!texture || !texture->img)
		return (-1);
	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (-1);
	bytes_per_pixel = texture->bpp / BITS_PER_BYTE;
	pixel = texture->addr + (y * texture->line_len) + (x * bytes_per_pixel);
	color = *(unsigned int *)pixel;
	return (color);
}
