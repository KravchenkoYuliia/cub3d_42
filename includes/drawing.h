/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:45:57 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/02 11:13:36 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

void	ft_render_and_display_image(t_cub *data);

void	ft_draw_ceiling(t_img *img, int color);
void	ft_draw_floor(t_img *img, int color);

/* UTILS */

void	ft_draw_pixel(t_image *image, int x, int y, int color);
int		get_texture_pixel(t_texture_image *texture, int x, int y);

# endif
