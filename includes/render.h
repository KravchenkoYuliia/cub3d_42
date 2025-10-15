/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 22:45:57 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 18:47:03 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

bool	ft_render_and_display_image(t_cub *data);
int		ft_run_game(t_cub *cub);

/* Drawing */

bool	ft_raycasting(t_cub *data);
bool	ft_draw_wall_column(t_cub *cub, t_ray *ray, int x);
bool	ft_draw_ceiling(t_image *img, int color);
bool	ft_draw_floor(t_image *img, int color);

/* UTILS */

void	ft_draw_pixel(t_image *image, int x, int y, int color);
int		ft_get_texture_pixel(t_texture *texture, int x, int y);

# endif
