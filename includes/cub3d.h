/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 10:18:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include "errors.h"
# include "structure.h"

# define WIN_WIDTH 2560 //TODO adapter a chaque ecran
# define WIN_HEIGHT 1440 //TODO adapter a chaque ecran

# define ESC_BUTTON 65307

void	ft_check_args(int ac, char **av);
t_cub	*ft_init_cub(void);
void	ft_init_mlx(t_cub *cub);
void	ft_parsing(t_cub *cub, char *descriptional_file);
void	ft_handle_every_line(t_cub *cub, char *line);
void	ft_check_line(t_cub *cub, char *line,
		char **elements_of_line, bool map_flag);
void	ft_read_fd_till_the_end(int fd);
void	ft_put_line_to_struct(void);
void	ft_hook(t_cub *cub);
void	ft_free_all(t_cub *cub);
int		ft_exit(t_cub *cub);

#endif
