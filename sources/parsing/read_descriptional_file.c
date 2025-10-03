/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_descriptional_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 13:07:22 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_read_fd_till_the_end(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
	}
}

void	ft_parsing(t_cub *cub, char *descriptional_file)
{
	bool	first_time;

	if (!cub || !descriptional_file)
		ft_free_all_and_exit(cub);
	ft_open_descriptional_file(cub, descriptional_file);
	first_time = true;
	cub->map_flag = false;
	cub->line = NULL;
	while (1)
	{
		cub->line = get_next_line(cub->fd);
		if (!cub->line)
		{
			if (first_time == true)
			{
				write(STDERR_FILENO, EMPTY_FILE, ft_strlen(EMPTY_FILE));
				ft_free_all_and_exit(cub);
			}
			break ;
		}
		cub->line_counter++;
		first_time = false;
		ft_handle_every_line(cub);
	}
	close(cub->fd);
	cub->fd = -1;
	cub->nb_of_line_in_file = cub->line_counter;
	ft_check_if_all_elements_are_in_file(cub);
	ft_fill_map_structure(cub, descriptional_file);
}
