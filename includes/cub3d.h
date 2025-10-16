/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 19:00:51 by jgossard         ###   ########.fr       */
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
# include <X11/keysym.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include "mlx_int.h"
# include "errors.h"
# include "variables.h"
# include "structure.h"
# include "utils.h"
# include "parsing.h"
# include "render.h"

//INITIALIZATION

t_cub		*ft_init_cub(void);
t_image		*ft_init_image(t_mlx *mlx, int width, int height);
bool		ft_init_mlx(t_cub *cub);
void		ft_init_map(t_cub *cub);
void		ft_init_before_new_reading_of_file(t_cub *cub);
t_player	*ft_init_player(t_cub *data);
t_ray		*ft_init_ray(t_player *player, int x_coordinate);
bool		ft_init_texture_image(t_mlx *mlx, t_texture *texture);

//EVENT

void		ft_events_listener(t_cub *cub);
bool		ft_move_player(t_player *player, t_cub *cub);

#endif
