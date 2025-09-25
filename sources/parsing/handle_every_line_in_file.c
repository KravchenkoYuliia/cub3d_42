/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_every_line_in_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 17:50:34 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 10:32:28 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_line(t_cub *cub, char *line,
		char **elements_of_line, bool map_flag)
{
	if (elements_of_line[0][0] == 'C' || elements_of_line[0][0] == 'F')
		printf("checking rgb colors\n");
		//ft_check_rgb_colors(elements_of_line, map_flag);
	else if (elements_of_line[0][0] == 'N' || elements_of_line[0][0] == 'S' ||
			elements_of_line[0][0] == 'W' || elements_of_line[0][0] == 'E')
		printf("checking texture\n");
		//ft_check_texture(elements_of_line, map_flag);
	else if (elements_of_line[0][0] == '1' || elements_of_line[0][0] == '0')
	{
		printf("checking map\n");
		//ft_check_map(line);
		map_flag = true;
	}
	else if (elements_of_line[0][0] <= 13)
		return ;
	else
	{
		write(STDERR_FILENO, INVALID_FILE, ft_strlen(INVALID_FILE));
		ft_read_fd_till_the_end(cub->fd);
		ft_free_char_tab(elements_of_line);
		free(line);
		ft_free_all(cub);
		exit(EXIT_FAILURE);
	}
}

void	ft_put_line_to_struct(void)
{
	printf("Everything is good\n");
}	

void	ft_handle_every_line(t_cub *cub, char *line)
{
	char	**elements_of_line;
	bool	map_flag;

	map_flag = false;
	elements_of_line = ft_split(line, ' ');
	if (!elements_of_line)
	{
		ft_read_fd_till_the_end(cub->fd);
		ft_free_all(cub);
		exit(EXIT_FAILURE);
	}
	ft_check_line(cub, line, elements_of_line, map_flag);
	ft_put_line_to_struct();
	ft_free_char_tab(elements_of_line);
	free(line);
}
