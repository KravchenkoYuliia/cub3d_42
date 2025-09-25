/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_descriptional_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 10:32:55 by yukravch         ###   ########.fr       */
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

static int	ft_open_descriptional_file(t_cub *cub, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, CANT_OPEN, ft_strlen(CANT_OPEN));
		ft_free_all(cub);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_parsing(t_cub *cub, char *descriptional_file)
{
	bool	first_time;
	char	*line;

	cub->fd = ft_open_descriptional_file(cub, descriptional_file);
	first_time = true;
	line = NULL;
	while (1)
	{
		line = get_next_line(cub->fd);
		if (!line)
		{
			if (first_time == true)
			{
				write(STDERR_FILENO, EMPTY_FILE, ft_strlen(EMPTY_FILE));
				ft_free_all(cub);
				exit(EXIT_FAILURE);
			}
			break ;
		}
		first_time = false;
		ft_handle_every_line(cub, line);
	}
}
