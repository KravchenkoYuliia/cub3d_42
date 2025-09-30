/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 11:10:32 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/30 17:07:17 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_this_is_texture(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (!cub->elements_of_line)
		ft_errormsg_free_parsing_free_all_exit(NULL, cub);
	if (cub->elements_of_line[0][0] == 'N'
			&& cub->elements_of_line[0][1] == 'O')
		return (true);
	if (cub->elements_of_line[0][0] == 'S'
			&& cub->elements_of_line[0][1] == 'O')
		return (true);
	if (cub->elements_of_line[0][0] == 'W'
			&& cub->elements_of_line[0][1] == 'E')
		return (true);
	if (cub->elements_of_line[0][0] == 'E'
			&& cub->elements_of_line[0][1] == 'A')
		return (true);
	return (false);
}

static void	ft_checking_direction(t_cub *cub)
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
		if (ft_strncmp(cub->elements_of_line[0], directions[i],
				ft_strlen(cub->elements_of_line[0])) == 0)
			return ;
		i++;
	}
	ft_errormsg_free_parsing_free_all_exit(WRONG_TEXTURE, cub);
}

static void	ft_checking_path(t_cub *cub)
{
	int		fd;
	char	*path_to_texture;

	path_to_texture = cub->elements_of_line[1];
	fd = open(path_to_texture, O_RDONLY);
	if (fd == -1)
		ft_errormsg_free_parsing_free_all_exit(WRONG_PATH_TEXTURE, cub);
	close(fd);
	if (ft_check_file_extension(path_to_texture, ".xpm") == false)
		ft_errormsg_free_parsing_free_all_exit(WRONG_EXTENSION, cub);
}

void	ft_check_texture(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (!cub->elements_of_line)
		ft_errormsg_free_parsing_free_all_exit(NULL, cub);
	if (cub->map_flag == true)
		ft_errormsg_free_parsing_free_all_exit(MAP_PLACING, cub);
	//must be 2 elements -> 1)direction 2)/path 3)NULL
	if (ft_checking_nb_of_elements_in_array(cub->elements_of_line, 2) == false)
		ft_errormsg_free_parsing_free_all_exit(WRONG_TEXTURE, cub);
	ft_checking_direction(cub);
	ft_checking_path(cub);
}
