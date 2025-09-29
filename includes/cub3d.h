/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/29 17:12:52 by yukravch         ###   ########.fr       */
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
# include <limits.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include "errors.h"
# include "structure.h"

# define WIN_WIDTH 2560 //TODO adapter a chaque ecran
# define WIN_HEIGHT 1440 //TODO adapter a chaque ecran

# define ESC_BUTTON 65307

//INITIALIZATION
t_cub	*ft_init_cub(void);
void	ft_init_mlx(t_cub *cub);

//PARSING
void	ft_check_args(int ac, char **av);
bool	ft_check_file_extension(char *file_name, char *extension);
void	ft_parsing(t_cub *cub, char *descriptional_file);
void	ft_handle_every_line(t_cub *cub);
void	ft_check_texture(t_cub *cub);
void	ft_check_rgb_colors(t_cub *cub);
void	ft_read_fd_till_the_end(int fd);

//EVENT
void	ft_hook(t_cub *cub);

//UTILS
bool	ft_checking_nb_of_elements_in_array(char **array, int expected_nb);
void	ft_cut_new_line_at_the_end(t_cub *cub);

//ERROR FREE EXIT
void	ft_error_msg_free_exit(char *msg, t_cub *cub);
int		ft_free_all_and_exit(t_cub *cub);

#endif
