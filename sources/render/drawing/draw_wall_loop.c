/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:25:04 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/16 14:28:26 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_texture_vars(t_texture *tex, t_ray *ray,
	double *step, double *tex_pos)
{
	*step = (double)tex->height / (double)ray->line_height;
	*tex_pos = (ray->draw_start - (WIN_HEIGHT / 2.0)
			+ (ray->line_height / 2.0)) * (*step);
}

static int	ft_limit_tex_y_to_range(int tex_y, int height)
{
	if (tex_y < 0)
		return (0);
	else if (tex_y >= height)
		return (height - 1);
	return (tex_y);
}

bool	ft_draw_wall_loop(t_cub *cub, t_texture *tex, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	if (!cub || !tex || !ray)
		return (false);
	ft_init_texture_vars(tex, ray, &step, &tex_pos);
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = ft_limit_tex_y_to_range((int)tex_pos, tex->height);
		tex_pos += step;
		color = ft_get_texture_pixel(tex, ray->tex_x, tex_y);
		if (color != -1)
			ft_draw_pixel(cub->image, x, y, color);
		y++;
	}
	return (true);
}
