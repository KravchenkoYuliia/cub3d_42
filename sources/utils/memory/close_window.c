/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:22:28 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/15 18:23:50 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_window(t_cub *cub)
{
	if (cub)
		ft_free_cub(cub);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
