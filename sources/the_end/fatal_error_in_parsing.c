/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_error_in_parsing.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:22:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 13:39:03 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fatal_error_in_parsing(char *msg, t_cub *cub)
{
	if (cub)
	{
		if (msg)
			write(STDERR_FILENO, msg, ft_strlen(msg));
		if (cub->fd != -1)
		{
			ft_read_fd_till_the_end(cub->fd);
			close(cub->fd);
		}
		if (cub->line)
			free(cub->line);
		if (cub->elements_of_line)
			ft_free_char_tab(cub->elements_of_line);
		ft_free_all_and_exit(cub);
	}
}
