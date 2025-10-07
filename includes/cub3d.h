/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 14:25:57 by yukravch         ###   ########.fr       */
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
# include "utils.h"
# include "parsing.h"

//INITIALIZATION

t_cub		*ft_init_cub(void);
void		ft_init_mlx(t_cub *cub);
void		ft_init_map(t_cub *cub);
void		ft_init_before_new_reading_of_file(t_cub *cub);
t_player	*ft_init_player(t_cub *data);
void		ft_print_map(char **map);

//EVENT

void		ft_hook(t_cub *cub);

#endif
