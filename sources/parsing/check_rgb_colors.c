/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:43:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/26 14:26:49 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_rgb_colors(t_cub *cub)
{
	//must be 2: 1)F/C     2)12,12,12     3)NULL
	if (ft_checking_nb_of_elements_in_array(cub->elements_of_line, 2) == false)
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
}
