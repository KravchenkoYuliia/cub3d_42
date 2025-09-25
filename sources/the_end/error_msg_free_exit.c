/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg_free_exit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 14:22:17 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 14:32:11 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error_msg_free_exit(char *msg, t_cub *cub)
{
	ft_read_fd_till_the_end(cub->fd);
	free(cub->line);
	ft_free_char_tab(cub->elements_of_line);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	ft_free_all_and_exit(cub);
}
