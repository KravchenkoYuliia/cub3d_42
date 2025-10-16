/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:51:38 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/16 14:14:12 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_calculate_step_and_side_distance(
	t_ray *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y)
			* ray->delta_dist_y;
	}
}

static bool	ft_perform_dda(t_ray *ray, char **map)
{
	if (!ray || !map || !*map)
		return (false);
	while (!ray->has_hit_wall)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->has_hit_wall = true;
	}
	return (true);
}

static bool	ft_calculate_perpendicular_wall_distance(
	t_ray *ray, t_player *player)
{
	double	numerator;

	if (!ray || !player)
		return (false);
	if (ray->side_hit == 0)
	{
		numerator = ray->map_x - player->pos_x + ((1 - ray->step_x) / 2);
		ray->perp_wall_dist = numerator / ray->ray_dir_x;
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	}
	else
	{
		numerator = ray->map_y - player->pos_y + ((1 - ray->step_y) / 2);
		ray->perp_wall_dist = numerator / ray->ray_dir_y;
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);
	return (true);
}

static bool	ft_calculate_line_height(t_ray *ray)
{
	if (!ray)
		return (false);
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -(ray->line_height) / 2 + WIN_HEIGHT / 2;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
	return (true);
}

bool	ft_raycasting(t_cub *data)
{
	t_ray	*ray;
	int		x_coordinate;

	if (!data)
		return (false);
	x_coordinate = 0;
	while (x_coordinate < WIN_WIDTH)
	{
		ray = ft_init_ray(data->player, x_coordinate);
		if (!ray)
			return (false);
		ft_calculate_step_and_side_distance(ray, data->player);
		if (!ft_perform_dda(ray, data->map.grid))
			return (free(ray), false);
		if (!ft_calculate_perpendicular_wall_distance(ray, data->player))
			return (free(ray), false);
		if (!ft_calculate_line_height(ray))
			return (free(ray), false);
		if (!ft_draw_wall_column(data, ray, x_coordinate))
			return (free(ray), false);
		free(ray);
		x_coordinate++;
	}
	return (true);
}
