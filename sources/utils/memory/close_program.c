/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:02:57 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 18:24:35 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_program(t_cub *cub, int exit_code)
{
	if (cub)
		ft_free_cub(cub);
	exit(exit_code);
	return (exit_code);
}
