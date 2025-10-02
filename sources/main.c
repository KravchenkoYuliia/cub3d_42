/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:44:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 17:24:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_check_args(ac, av);
	cub = ft_init_cub();
	ft_parsing(cub, av[1]);
	ft_init_mlx(cub);
	return (0);
}
