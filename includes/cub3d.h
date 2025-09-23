/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:46:13 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 16:07:31 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/minilibx-linux/mlx_int.h"
# include "../libs/libft/include/libft.h"

# define WIN_WIDTH 2560 //TODO adapter a chaque ecran
# define WIN_HEIGHT 1440 //TODO adapter a chaque ecran

# define ESC_BUTTON 65307

typedef struct s_mlx{
	void	*ptr;
	void	*win;
	void	*img;
}	t_mlx;

void	ft_init_win(void);
void	ft_hook(t_mlx *mlx_struct);
int		ft_exit(t_mlx *mlx_struct);

#endif
