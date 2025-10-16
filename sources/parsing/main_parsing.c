/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:07 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 15:17:14 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_parsing(t_cub *cub, char *descriptional_file)
{
	if (!cub || !descriptional_file)
		ft_close_program(cub, EXIT_FAILURE);
	ft_open_descriptional_file(cub, descriptional_file);
	ft_reading_loop(cub);
	ft_init_before_new_reading_of_file(cub);
	ft_check_if_all_elements_are_in_file(cub);
	if (cub->map_last_line == 0)
		cub->map_last_line = cub->line_counter;
	ft_fill_map_structure(cub, descriptional_file);
	ft_handle_spaces_in_map(cub);
	ft_path_finding(cub);
}

/*
Parsing flow

	ft_parsing()
		├── ft_open_descriptional_file()
		├── ft_reading_loop()
		│	├── ft_handle_every_line()
		│	│	├── ft_check_line()
		│	│	├── ft_put_line_to_struct()
		│	│		├── ft_choose_direction_if_texture() ← texture paths stored here
		│	│		└── ft_choose_surface_if_color()
		│	└── (continues line by line)
		├── ft_init_before_new_reading_of_file()
		├── ft_check_if_all_elements_are_in_file()
		├── ft_fill_map_structure()
		├── ft_handle_spaces_in_map()
		└── ft_path_finding()

*/
