/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:44:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 19:03:34 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_check_args(ac, av);
	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		exit(EXIT_FAILURE);
	ft_init_win(cub);
	return (0);
}
