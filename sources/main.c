/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:44:37 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 18:37:50 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	*cub;

	ft_check_args(ac, av);
	cub = ft_init_cub();
	if (!cub)
		exit(EXIT_FAILURE);
	if (!ft_init_mlx(cub))
		ft_close_program(cub, EXIT_FAILURE);
	ft_parsing(cub, av[1]);
	cub->player = ft_init_player(cub);
	if (!cub->player)
		ft_close_program(cub, EXIT_FAILURE);
	if (!ft_load_all_textures(cub))
		ft_close_program(cub, EXIT_FAILURE);
	if (ft_run_game(cub) == EXIT_FAILURE)
		ft_close_program(cub, EXIT_FAILURE);
	ft_events_listener(cub);
	return (0);
}
