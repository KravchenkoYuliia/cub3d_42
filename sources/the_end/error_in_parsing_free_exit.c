/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_in_parsing_free_exit.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:22:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/30 17:03:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_errormsg_free_parsing_free_all_exit(char *msg, t_cub *cub)
{
	if (cub)
	{
		if (msg)
			write(STDERR_FILENO, msg, ft_strlen(msg));
		if (cub->fd != -1)
			ft_read_fd_till_the_end(cub->fd);
		if (cub->line)
			free(cub->line);
		if (cub->elements_of_line)
			ft_free_char_tab(cub->elements_of_line);
		ft_free_all_and_exit(cub);
	}
}
