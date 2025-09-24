/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:27:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 11:18:48 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_check_file_extension(char *scene_description)
{
	int		len;
	int		len_of_extension;
	char	extension[5];

	len = ft_strlen(scene_description);
	if (len < 5)
	{
		write(STDERR_FILENO, WRONG_ARGV, ft_strlen(WRONG_ARGV));
		exit(EXIT_FAILURE);
	}
	len_of_extension = ft_strlen(&scene_description[len - 5]);
	ft_strlcpy(extension, &scene_description[len - 4], len_of_extension);
	if (ft_strncmp(&scene_description[len - 4], ".cub", len_of_extension) != 0)
	{
		write(STDERR_FILENO, WRONG_ARGV, ft_strlen(WRONG_ARGV));
		exit(EXIT_FAILURE);
	}
}

void	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(STDERR_FILENO, NB_OF_ARGS, ft_strlen(NB_OF_ARGS));
		exit(EXIT_FAILURE);
	}
	ft_check_file_extension(av[1]);
}
