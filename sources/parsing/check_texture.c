/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:10:32 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 13:13:33 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//NO /path_to_texture

static void	ft_checking_number_of_elements(t_cub *cub,
		char *line, char **elements_of_line)
{
	int	i;

	i = 0;
	while (elements_of_line[i])
		i++;
	if (i != 2)
	{
		ft_read_fd_till_the_end(cub->fd);
		free(line);
		ft_free_char_tab(elements_of_line);
		write(STDERR_FILENO, WRONG_TEXTURE, ft_strlen(WRONG_TEXTURE));
		ft_free_all_and_exit(cub);
	}
}

static void	ft_checking_direction(t_cub *cub,
		char *line, char **elements_of_line)
{
	int		i;
	char	*directions[4];

	i = 0;
	directions[0] = "NO";
	directions[1] = "SO";
	directions[2] = "WE";
	directions[3] = "EA";
	while (i < 4)
	{
		if (ft_strncmp(elements_of_line[0], directions[i],
				ft_strlen(elements_of_line[0])) == 0)
			return ;
		i++;
	}
	ft_read_fd_till_the_end(cub->fd);
	free(line);
	ft_free_char_tab(elements_of_line);
	write(STDERR_FILENO, WRONG_TEXTURE, ft_strlen(WRONG_TEXTURE));
	ft_free_all_and_exit(cub);
}

void	ft_check_texture(t_cub *cub, char *line, char **elements_of_line)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (!elements_of_line)
	{
		ft_read_fd_till_the_end(cub->fd);
		ft_free_char_tab(elements_of_line);
		ft_free_all_and_exit(cub);
	}
	//must be 2 elements -> 1)direction 2)/path 3)NULL
	ft_checking_number_of_elements(cub, line, elements_of_line);
	ft_checking_direction(cub, line, elements_of_line);
}
