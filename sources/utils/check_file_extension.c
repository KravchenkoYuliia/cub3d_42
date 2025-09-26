/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_extension.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:50:44 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/26 13:36:42 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_check_file_extension(char *file_name, char *extension)
{
	int	len_of_file_name;
	int	len_of_extension;

	len_of_file_name = ft_strlen(file_name);
	len_of_extension = ft_strlen(extension);
	if (len_of_file_name < len_of_extension + 1)
		return (false);
	if (ft_strncmp(&file_name[len_of_file_name - len_of_extension],
			extension, len_of_extension) != 0)
		return (false);
	return (true);
}
