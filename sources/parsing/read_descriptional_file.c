/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_descriptional_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/13 17:55:40 by jgossard         ###   ########.fr       */
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

void	ft_reading_loop(t_cub *cub)
{
	bool	first_time;

	first_time = true;
	while (1)
	{
		cub->line = get_next_line(cub->fd);
		if (!cub->line)
		{
			if (first_time == true)
			{
				write(STDERR_FILENO, EMPTY_FILE, ft_strlen(EMPTY_FILE));
				ft_close_program(cub, EXIT_FAILURE);
			}
			break ;
		}
		cub->line_counter++;
		first_time = false;
		ft_handle_every_line(cub);
	}
}
