/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:27:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/26 13:11:01 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(STDERR_FILENO, NB_OF_ARGS, ft_strlen(NB_OF_ARGS));
		exit(EXIT_FAILURE);
	}
	if (ft_check_file_extension(av[1], ".cub") == false)
	{
		write(STDERR_FILENO, WRONG_ARGV, ft_strlen(WRONG_ARGV));
		exit(EXIT_FAILURE);
	}
}
