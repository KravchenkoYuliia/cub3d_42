/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 14:41:46 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free_all_and_exit(t_cub *cub)
{
	if (cub)
		ft_free_cub(cub);
	exit(EXIT_SUCCESS);
	return (0);
}
