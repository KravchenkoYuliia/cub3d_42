/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:43:22 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 18:39:38 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_run_game(t_cub *cub)
{
	if (!cub || !cub->player)
		return (EXIT_FAILURE);
	if (!ft_render_and_display_image(cub))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
