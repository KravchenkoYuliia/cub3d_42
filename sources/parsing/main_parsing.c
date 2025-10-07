/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_of_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:07 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 15:17:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_cub *cub, char *descriptional_file)
{
	if (!cub || !descriptional_file)
		ft_free_all_and_exit(cub);
	ft_open_descriptional_file(cub, descriptional_file);
	ft_reading_loop(cub);
	ft_init_before_new_reading_of_file(cub);
	ft_check_if_all_elements_are_in_file(cub);
	if (cub->map_last_line == 0)
		cub->map_last_line = cub->line_counter;
	ft_fill_map_structure(cub, descriptional_file);
	ft_handle_spaces_in_map(cub);
}
