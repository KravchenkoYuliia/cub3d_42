/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:20:02 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 17:39:19 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_is_wall(t_cub *cub, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0
		|| map_y >= cub->map.height || map_x >= cub->map.width)
		return (true);
	return (cub->map.grid[map_y][map_x] == '1');
}

static void	ft_move_vertical(t_player *player, t_cub *cub, float speed)
{
	double	new_x;
	double	new_y;
	double	delta_x;
	double	delta_y;

	delta_x = player->dir_x * speed;
	delta_y = player->dir_y * speed;
	if (player->input.move_forward)
	{
		new_x = player->pos_x + delta_x;
		new_y = player->pos_y + delta_y;
		if (!ft_is_wall(cub, new_x, player->pos_y))
			player->pos_x = new_x;
		if (!ft_is_wall(cub, player->pos_x, new_y))
			player->pos_y = new_y;
	}
	if (player->input.move_backward)
	{
		new_x = player->pos_x - delta_x;
		new_y = player->pos_y - player->dir_y * speed;
		if (!ft_is_wall(cub, new_x, player->pos_y))
			player->pos_x = new_x;
		if (!ft_is_wall(cub, player->pos_x, new_y))
			player->pos_y = new_y;
	}
}

static void	ft_move_horizontal(t_player *player, t_cub *cub, float speed)
{
	double	side_step_x;
	double	side_step_y;
	double	new_x;
	double	new_y;

	side_step_x = -player->dir_y * speed;
	side_step_y = player->dir_x * speed;
	if (player->input.move_left)
	{
		new_x = player->pos_x - side_step_x;
		new_y = player->pos_y - side_step_y;
		if (!ft_is_wall(cub, new_x, player->pos_y))
			player->pos_x = new_x;
		if (!ft_is_wall(cub, player->pos_x, new_y))
			player->pos_y = new_y;
	}
	if (player->input.move_right)
	{
		new_x = player->pos_x + side_step_x;
		new_y = player->pos_y + side_step_y;
		if (!ft_is_wall(cub, new_x, player->pos_y))
			player->pos_x = new_x;
		if (!ft_is_wall(cub, player->pos_x, new_y))
			player->pos_y = new_y;
	}
}

static void	ft_rotate_player(t_player *player)
{
	if (player->input.camera_turn_left)
		player->dir_angle -= player->rotate_speed;
	if (player->input.camera_turn_right)
		player->dir_angle += player->rotate_speed;

	if (player->dir_angle < 0.0f)
		player->dir_angle += 2.0f * M_PI;
	else if (player->dir_angle >= 2.0f * M_PI)
		player->dir_angle -= 2.0f * M_PI;
}

bool	ft_move_player(t_player *player, t_cub *cub)
{
	float	speed;

	if (!player || !cub)
		return (false);
	speed = player->move_speed;
	ft_move_vertical(player, cub, speed);
	ft_move_horizontal(player, cub, speed);
	ft_rotate_player(player);
	ft_update_player_vectors(player);
	return (true);
}
