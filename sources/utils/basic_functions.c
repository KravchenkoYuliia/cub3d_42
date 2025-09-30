/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:14:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/30 13:20:02 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cut_new_line_at_the_end(char *line)
{
	int	last_index;

	last_index = ft_strlen(line) - 1;
	if (last_index > 0 && line[last_index])
		line[last_index] = '\0';
}

bool	ft_checking_nb_of_elements_in_array(char **array, int expected_nb)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	if (i != expected_nb)
		return (false);
	return (true);
}
