/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/25 11:07:06 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef enum e_direction {
	NORTH,
	SOUTH,
	WEST,
	EAST,
}	t_direction;

typedef enum e_surface_type {
	SURFACE_FLOOR,
	SURFACE_CEILING,
}	t_surface_type;

typedef enum e_button {
	W,
	A,
	S,
	D,
	LEFT,
	RIGHT,
}	t_button;

typedef struct s_texture {
	t_direction	direction;
	char		*path;
}	t_texture;

typedef struct s_surface_color {
	t_surface_type	surface_type;
	int				*colors;
}	t_surface_color;

typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color; //TODO utile?
}	t_point;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map {
	t_point	**grid;
}	t_map;

typedef struct s_cub {
	t_map		*map;
	t_texture	*texture;
	t_surface_color	*surface_color;
	t_mlx		*mlx;
// parsing:
	int			fd;
	bool		map_flag;	
}	t_cub;

#endif
