/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 11:52:51 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef enum e_elements_of_parsing {
	FREE = 0,
	TAKEN = 1,
	MAP = 'M',
	NO = 'N',
	SO = 'S',
	WE = 'W',
	EA = 'E',
	F = 'F',
	C = 'C',
}	t_elements_of_parsing;
/*
typedef enum e_direction {
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
	EAST = 'E',
}	t_direction;
*/
/*
typedef enum e_surface_type {
	SURFACE_FLOOR = 'F',
	SURFACE_CEILING = 'C',
}	t_surface_type;
*/

typedef enum e_button {
	BUTTON_W,
	BUTTON_A,
	BUTTON_S,
	BUTTON_D,
	BUTTON_LEFT,
	BUTTON_RIGHT
}	t_button;

typedef struct s_texture {
	char		*path;
}	t_texture;

typedef struct s_surface_color {
	int	surface_type;
	int	*colors;
}	t_surface_color;
/*
typedef struct s_point {
	int	x;
	int	y;
	int	z;
	int	color; //TODO utile?
}	t_point;
*/
typedef struct s_mlx {
	void	*ptr;
	void	*win;
	void	*img;
}	t_mlx;

typedef struct s_map {
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_elements_tracker {
	int	north;
	int	south;
	int	east;
	int	west;
	int	floor;
	int	ceiling;
	int	map;
}	t_elements_tracker;

typedef struct s_cub {
	t_map					*map;

	t_texture				north;
	t_texture				south;
	t_texture				east;
	t_texture				west;

	t_surface_color			*surface_color; //surface_color[0] = Floor; 
							//surface_color[1] = Ceiling
	t_mlx					*mlx;

// PARSING
	int						fd;
	int						line_counter;
	bool					map_flag;
	char					*line;
	char					**elements_of_line;
	t_elements_of_parsing	type;
	t_elements_tracker		elements_tracker;
// MAP PARSING
	int						map_first_line;
	size_t						map_line_counter;
	size_t						map_longest_line;
}	t_cub;

#endif
