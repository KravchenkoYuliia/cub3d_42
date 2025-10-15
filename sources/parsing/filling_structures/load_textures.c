/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:27:16 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/10 11:27:27 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_load_all_textures(t_cub *data)
{
	if (!data || !data->mlx)
		return (false);
	if (!ft_init_texture_image(data->mlx, &data->north))
		return (false);
	if (!ft_init_texture_image(data->mlx, &data->south))
		return (false);
	if (!ft_init_texture_image(data->mlx, &data->east))
		return (false);
	if (!ft_init_texture_image(data->mlx, &data->west))
		return (false);
	return (true);
}
