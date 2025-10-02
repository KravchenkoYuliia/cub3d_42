/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/02 16:12:33 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _GNU_SOURCE // to use M_PI, need to be declared before including math.h
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include "errors.h"
# include "variables.h"
# include "structure.h"
# include "drawing.h"

//INITIALIZATION
t_cub	*ft_init_cub(void);
void	ft_init_mlx(t_cub *cub);

//PARSING
void	ft_check_args(int ac, char **av);
void	ft_parsing(t_cub *cub, char *descriptional_file);
void	ft_handle_every_line(t_cub *cub);
bool	ft_this_is_texture(t_cub *cub);
void	ft_check_texture(t_cub *cub);
void	ft_check_rgb_colors(t_cub *cub);
void	ft_read_fd_till_the_end(int fd);
void	ft_choose_direction_if_texture(t_cub *cub);
void	ft_check_if_all_elements_are_in_file(t_cub *cub);

//EVENT
void	ft_hook(t_cub *cub);

//UTILS
bool	ft_checking_nb_of_elements_in_array(char **array, int expected_nb);
void	ft_cut_new_line_at_the_end(char *line);
bool	ft_line_only_has_whitespaces(char *line);
bool	ft_check_file_extension(char *file_name, char *extension);
char	*ft_strcpy(char *dest, char *src);

//ERROR FREE EXIT
void	ft_fatal_error_in_parsing(char *msg, t_cub *cub);
int		ft_free_all_and_exit(t_cub *cub);

#endif
