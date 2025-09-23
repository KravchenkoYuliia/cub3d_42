/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/23 19:17:00 by yukravch         ###   ########.fr       */
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

typedef enum e_FC {
	FLOOR,
	CEILING,
}	t_FC;

typedef enum e_button {
	W,
	A,
	S,
	D,
	LEFT,
	RIGHT,
}	t_button;

typedef struct s_texture {
	t_direction	*direction;
	char		*path;
}	t_texture;

typedef struct s_fc_color {
	t_FC	*fc;
	int		*colors;
}	t_fc_color;

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
	t_fc_color	*fc;
	t_mlx		*mlx;
}	t_cub;

#endif
