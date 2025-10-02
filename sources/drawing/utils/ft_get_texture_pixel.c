/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_texture_pixel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:02:00 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/02 11:12:25 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_texture_pixel(t_texture_image *texture, int x, int y)
{
	char	*pixel;
	int		color;
	int		bytes_per_pixel;

	if (!texture || !texture->img)
		return (0);
	if (x < 0 || y < 0 || x >= texture->width || y >= texture->height)
		return (0);
	bytes_per_pixel = texture->img->bpp / 8;
	pixel = texture->img->addr + (y * texture->img->line_len)
		+ (x * bytes_per_pixel);
	color = *(unsigned int *)pixel;
	return (color);
}
