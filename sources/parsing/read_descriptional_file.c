/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_descriptional_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:19:02 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 16:29:30 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_line(t_cub *cub, char *line,
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
	else
	{
		write(STDERR_FILENO, INVALID_FILE, ft_strlen(INVALID_FILE));
		ft_free_char_tab(elements_of_line);
		free(line);
		ft_free_all(cub);
		exit(EXIT_FAILURE);
	}
}

static void	ft_put_line_to_struct(void)
{
	printf("Everything is good\n");
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
	int		fd;
	bool	map_flag;
	char	*line;
	char	**elements_of_line;

	fd = ft_open_descriptional_file(cub, descriptional_file);
	map_flag = false;
	line = NULL;
	elements_of_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		elements_of_line = ft_split(line, ' ');
		ft_check_line(cub, line, elements_of_line, map_flag);
		ft_put_line_to_struct();
		ft_free_char_tab(elements_of_line);
		free(line);
	}
}
