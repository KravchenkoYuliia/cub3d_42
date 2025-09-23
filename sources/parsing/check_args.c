/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 17:27:47 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 17:39:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, NB_OF_ARGS, ft_strlen(NB_OF_ARGS));
		exit(EXIT_FAILURE);
	}
	(void)av;
}
