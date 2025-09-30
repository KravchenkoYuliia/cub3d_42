/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_every_line_in_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:50:34 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/30 14:46:30 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line(t_cub *cub)
{
	if (cub->elements_of_line[0][0] == 'C' ||
			cub->elements_of_line[0][0] == 'F')
		ft_check_rgb_colors(cub);
	else if (ft_this_is_texture(cub) == true)
		ft_check_texture(cub);
	else
	{
		printf("checking map\n");
		//ft_check_map(line);
		cub->map_flag = true;
	}
}

static void	ft_put_line_to_struct(t_cub *cub)
{
	(void)cub;
}	

void	ft_handle_every_line(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (ft_line_only_has_whitespaces(cub->line) == true)
	{
		free(cub->line);
		return ;
	}
	ft_cut_new_line_at_the_end(cub->line);
	cub->elements_of_line = ft_split(cub->line, ' ');
	if (!cub->elements_of_line)
		ft_error_msg_free_exit(NULL, cub);
	ft_check_line(cub);
	ft_put_line_to_struct(cub);
	ft_free_char_tab(cub->elements_of_line);
	free(cub->line);
}
