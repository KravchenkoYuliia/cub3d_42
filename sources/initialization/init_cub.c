/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 12:20:00 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/24 16:01:31 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cub	*ft_init_cub(void)
{
	t_cub	*cub;

	cub = ft_alloc_struct(sizeof(t_cub));
	if (!cub)
		exit(EXIT_FAILURE);
	cub->texture = calloc(5, sizeof(t_texture)); //4 directions + NULL
	if (!cub->texture)
	{
		free(cub);
		exit(EXIT_FAILURE);
	}
	return (cub);
}
