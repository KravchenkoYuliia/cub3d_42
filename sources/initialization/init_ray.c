/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 11:24:48 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 17:20:31 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_set_delta_distance(t_ray *rc)
{
	if (!rc)
		return (false);
	if (rc->ray_dir_x == 0)
		rc->delta_dist_x = INFINITY;
	else
		rc->delta_dist_x = fabs(1 / rc->ray_dir_x);
	if (rc->ray_dir_y == 0)
		rc->delta_dist_y = INFINITY;
	else
		rc->delta_dist_y = fabs(1 / rc->ray_dir_y);
	return (true);
}

t_ray	*ft_init_ray(t_player *player, int x_coordinate)
{
	t_ray	*ray;
	double			camera_x;

	if (!player || x_coordinate < 0 || x_coordinate > WIN_WIDTH)
		return (NULL);
	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	camera_x = (2.0 * x_coordinate / (double)WIN_WIDTH) - 1.0;
	ray->ray_dir_x = player->dir_x + player->plane_x * camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * camera_x;
	ray->map_x = (int)player->pos_x;
	ray->map_y = (int)player->pos_y;
	if (!ft_set_delta_distance(ray))
		return (free(ray), NULL);
	ray->has_hit_wall = false;
	return (ray);
}
