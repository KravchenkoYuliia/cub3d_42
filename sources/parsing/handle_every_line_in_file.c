/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_every_line_in_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:50:34 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 14:43:24 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line(t_cub *cub)
{
	if (cub->elements_of_line[0][0] == 'C' ||
			cub->elements_of_line[0][0] == 'F')
		printf("checking rgb colors\n");
		//ft_check_rgb_colors(elements_of_line, map_flag);
	else if (cub->elements_of_line[0][0] == 'N' ||
			cub->elements_of_line[0][0] == 'S' ||
			cub->elements_of_line[0][0] == 'W' ||
			cub->elements_of_line[0][0] == 'E')
		ft_check_texture(cub);
	else if (cub->elements_of_line[0][0] == '1' ||
			cub->elements_of_line[0][0] == '0')
	{
		printf("checking map\n");
		//ft_check_map(line);
		cub->map_flag = true;
	}
	else if (cub->elements_of_line[0][0] <= 13)
		return ;
	else
	{
		write(STDERR_FILENO, INVALID_FILE, ft_strlen(INVALID_FILE));
		ft_read_fd_till_the_end(cub->fd);
		ft_free_char_tab(cub->elements_of_line);
		free(cub->line);
		ft_free_all_and_exit(cub);
	}
}

static void	ft_put_line_to_struct(void)
{
	printf("Everything is good\n");
}	

void	ft_handle_every_line(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	cub->map_flag = false;
	cub->elements_of_line = NULL;
	cub->elements_of_line = ft_split(cub->line, ' ');
	if (!cub->elements_of_line)
	{
		ft_read_fd_till_the_end(cub->fd);
		ft_free_all_and_exit(cub);
	}
	ft_check_line(cub);
	ft_put_line_to_struct();
	ft_free_char_tab(cub->elements_of_line);
	free(cub->line);
}
