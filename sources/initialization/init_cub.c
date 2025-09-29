/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/29 16:17:57 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		exit(EXIT_FAILURE);
	return (cub);
}
