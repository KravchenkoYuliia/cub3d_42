/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_surface_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:21:04 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 17:49:16 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static void	ft_fill_color_structure(t_cub *cub,
		int elements_tracker, t_surface_color *surface)
{
	char	**numbers;
	int		rgb[3];
	int		i;

	if (elements_tracker == TAKEN)
		ft_fatal_error_in_parsing(DOUBLE_ELEMENT, cub);
	numbers = ft_split(cub->elements_of_line[1], ',');
	if (!numbers)
		ft_fatal_error_in_parsing(INVALID_COLOR, cub);
	i = 0;
	while (i < RGB_SIZE)
	{
		rgb[i] = ft_atoi(numbers[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_fatal_error_in_parsing(INVALID_COLOR, cub);
		i++;
	}
	ft_free_char_tab(numbers);
	surface->color = ft_rgb_to_int(rgb[0], rgb[1], rgb[2]);
}

void	ft_parse_surface_color(t_cub *cub)
{
	if (cub->type == F)
	{
		ft_fill_color_structure(cub,
			cub->elements_tracker.floor,
			&cub->surface_color[0]);
		cub->elements_tracker.floor = TAKEN;
	}
	else if (cub->type == C)
	{
		ft_fill_color_structure(cub,
			cub->elements_tracker.ceiling,
			&cub->surface_color[1]);
		cub->elements_tracker.ceiling = TAKEN;
	}
}
