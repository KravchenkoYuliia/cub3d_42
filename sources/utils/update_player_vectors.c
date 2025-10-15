/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_vectors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:53:35 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 16:55:22 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_update_player_vectors(t_player *player)
{
	if (!player)
		return ;
	player->dir_x = cos(player->dir_angle);
	player->dir_y = sin(player->dir_angle);
	player->plane_x = -player->dir_y * PLANE_SCALE;
	player->plane_y = player->dir_x * PLANE_SCALE;
}
