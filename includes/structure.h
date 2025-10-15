/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 16:49:18 by yukravch         ###   ########.fr       */
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
	DONE = 'x',
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
	// void	*img; // move to its own structure
}	t_mlx;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;

// /* ########  TEXTURE STRUCT PART  ######## */

typedef struct s_texture
{
	char	*path;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture;

/* ########  MAP STRUCT PART  ######## */

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

/* ########  PLAYER STRUCT PART  ######## */

typedef struct s_input
{
	bool		move_forward;
	bool		move_backward;
	bool		move_left;
	bool		move_right;
	bool		camera_turn_left;
	bool		camera_turn_right;
}	t_input;

typedef struct s_player {
	// Player position on the map
	double	pos_x;
	double	pos_y;
	// Player direction vector on the map
	double	dir_angle;
	double	dir_x;
	double	dir_y;
	// 2D Camera plane
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rotate_speed;
	t_input	input;
}	t_player;

/* ########  IMAGE + RENDERING + RAYCASTING STRUCT PART  ######## */

typedef struct s_raycasting {
	// Ray direction linked to the player position on the map
	double	ray_dir_x;
	double	ray_dir_y;
	// Tab cell associated with
	int		map_x;
	int		map_y;
	// Distance from the current position to the next x- or y-side in the map grid.
	// Helps in stepping through the grid to find wall hits.
	double	side_dist_x;
	double	side_dist_y;
	// DDA info - Distance ray
	// Distance the ray has to travel in world units to go from one x- or y-side to the next.
	double	delta_dist_x;
	double	delta_dist_y;
	// distance to wall, help avoid to have fish-eye effect
	double	perp_wall_dist;
	// Step in x
	int		step_x;
	int		step_y;
	bool	has_hit_wall;
	// Indicates which side of the wall was hit:
	// Useful for determining which texture to use or for shading.
	// 0 → NS wall (x-side was hit).
	// 1 → EW wall (y-side was hit).
	int		side_hit;
}	t_raycasting;

typedef struct s_draw
{
	int		line_height; // height of line to draw
	int		draw_start;	// lowest pixel of wall
	int		draw_end; // highest pixel of wall
	int		tex_x; // x coordinate of texture
	double	tex_pos; // starting texture position
	double	step; // how much to increase tex_pos per screen pixel
}	t_draw;

/* ########  MAIN STRUCT PART  ######## */
typedef struct s_cub {
	t_map					map;
	t_texture				north;
	t_texture				south;
	t_texture				east;
	t_texture				west;
	t_mlx					*mlx;
	t_surface_color			*surface_color; //surface_color[0] = Floor;
							//surface_color[1] = Ceiling
	// PARSING
	int						fd;
	int						line_counter;
	int						nb_of_line_in_file;
	bool					map_flag;
	char					*line;
	char					**elements_of_line;
	t_elements_of_parsing	type;
	t_elements_tracker		elements_tracker;
	// MAP PARSING
	int						map_first_line;
	int						map_last_line;
	size_t					map_line_counter;
	size_t					map_longest_line;
	bool					map_is_finished;
	int						nb_of_players;
	char					**map_to_check;
	int						x_coordinate_of_player;
	int						y_coordinate_of_player;
	/* ########  PLAYER DATA  ######## */
	t_player				*player;
	/* ########  FRAME BUFFER (off-screen image) ######## */
	t_image					*image;
	/* ########  WINDOW / SCREEN INFO ######## */
	int						screen_width;
	int						screen_height;
}	t_cub;

#endif
