/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_column.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:41:41 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 17:48:02 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_texture	*ft_select_texture(t_cub *cub, t_ray *ray)
{
	if (!cub || !ray)
		return (NULL);
	if (ray->side_hit == 0)
	{
		if (ray->ray_dir_x > 0)
			return (&cub->east);
		return (&cub->west);
	}
	if (ray->ray_dir_y > 0)
		return (&cub->south);
	return (&cub->north);
}

static int	ft_compute_tex_x(t_texture *tex, t_ray *ray)
{
	int	tex_x;

	if (!tex || !ray || tex->width <= 0)
		return (-1);
	tex_x = (int)(ray->wall_x * (double)tex->width);
	if ((ray->side_hit == 0 && ray->ray_dir_x > 0)
		|| (ray->side_hit == 1 && ray->ray_dir_y < 0))
	{
		tex_x = tex->width - tex_x - 1;
	}
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	return (tex_x);
}

static bool	ft_draw_wall_loop(
	t_cub *cub, t_texture *tex, t_ray *ray, int x)
{
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;
	int		color;

	if (!cub || !tex || !ray)
		return (false);
	step = (double)tex->height / (double)ray->line_height;
	tex_pos = (ray->draw_start - (WIN_HEIGHT / 2.0)
				+ (ray->line_height / 2.0)) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		tex_pos += step;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		color = ft_get_texture_pixel(tex, ray->tex_x, tex_y);
		if (color == -1)
		{
			y++;
			continue ; // TODO: why not returning false ?
		}
		ft_draw_pixel(cub->image, x, y, color);
		y++;
	}
	return (true);
}

bool	ft_draw_wall_column(t_cub *cub, t_ray *ray, int x)
{
	t_texture	*tex;

	if (!cub || !ray)
		return (false);
	if (x < 0 || x >= WIN_WIDTH)
		return (false);
	tex = ft_select_texture(cub, ray);
	if (!tex || !tex->img || tex->width <= 0 || tex->height <= 0)
		return (false);
	ray->tex_x = ft_compute_tex_x(tex, ray);
	if (ray->tex_x < 0 || ray->tex_x >= tex->width)
		return (false);
	return (ft_draw_wall_loop(cub, tex, ray, x));
}
