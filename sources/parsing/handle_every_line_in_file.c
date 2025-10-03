/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_every_line_in_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:50:34 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 13:43:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line(t_cub *cub)
{
	if (cub->elements_of_line[0][0] == 'C' ||
			cub->elements_of_line[0][0] == 'F')
	{
		ft_check_rgb_colors(cub);
		cub->type = cub->elements_of_line[0][0];
	}
	else if (ft_this_is_texture(cub) == true)
	{
		ft_check_texture(cub);
		cub->type = cub->elements_of_line[0][0];
	}
	else
	{
		ft_check_map(cub);
		if (cub->map_flag == false)
			cub->map_first_line = cub->line_counter;
		cub->map_flag = true;
		cub->type = MAP;
	}
}

static void	ft_put_line_to_struct(t_cub *cub)
{
	ft_choose_direction_if_texture(cub);
	ft_choose_surface_if_color(cub);
	ft_free_char_tab(cub->elements_of_line);
	cub->elements_of_line = NULL;
	if (cub->type == MAP)
	{
		cub->map_line_counter++;
		cub->elements_tracker.map = TAKEN;
		if (ft_strlen(cub->line) > cub->map_longest_line)
			cub->map_longest_line = ft_strlen(cub->line);
	}
}	

void	ft_handle_every_line(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (ft_line_only_has_whitespaces(cub->line) == true) //empty line
	{
		if (cub->map_flag == true && cub->map_is_finished == false)
			cub->map_is_finished = true;
		free(cub->line);
		return ;
	}
	ft_cut_new_line_at_the_end(cub->line);
	cub->elements_of_line = ft_split(cub->line, ' ');
	if (!cub->elements_of_line)
		ft_fatal_error_in_parsing(NULL, cub);
	ft_check_line(cub);
	ft_put_line_to_struct(cub);
	free(cub->line);
}
