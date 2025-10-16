/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/16 14:46:22 by jgossard         ###   ########.fr       */
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
	int	color;
}	t_surface_color;

typedef struct s_mlx {
	void	*ptr;
	void	*win;
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
	double	pos_x;
	double	pos_y;
	double	dir_angle;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rotate_speed;
	t_input	input;
}	t_player;

/* ########  IMAGE + RENDERING + RAYCASTING STRUCT PART  ######## */
/**
 * @brief Represents a single ray cast in the 2D raycasting engine.
 *
 * The t_ray structure holds all the data needed to cast a ray from the player's
 * point of view, determine where it intersects with the world, and render a vertical
 * wall slice based on that intersection. It includes directional information,
 * distance calculations, texture mapping details, and render bounds.
 *
 * Fields:
 * 
 * - ray_dir_x / ray_dir_y:
 *     The X and Y components of the ray's direction vector.
 *
 * - map_x / map_y:
 *     The current grid cell (map square) that the ray is in.
 *
 * - side_dist_x / side_dist_y:
 *     Distance from the player’s position to the first X-side or Y-side of the grid.
 *
 * - delta_dist_x / delta_dist_y:
 *     Distance the ray travels between each X-side or Y-side. These values are
 *     constant for each ray and used to incrementally step through the map.
 *
 * - perp_wall_dist:
 *     The perpendicular distance from the player to the wall. Used to avoid fish-eye
 *     distortion and to scale the wall slice correctly.
 *
 * - step_x / step_y:
 *     The direction to step in the map grid (either +1 or -1) for both axes.
 *
 * - has_hit_wall:
 *     Boolean flag indicating whether the ray has hit a wall.
 *
 * - side_hit:
 *     Which side of the wall was hit: 0 for an X-side, 1 for a Y-side. Useful for
 *     shading or texture orientation.
 *
 * - wall_dist:
 *     The actual distance from the player to the wall hit (redundant in some cases
 *     with perp_wall_dist but can be kept for clarity or debug purposes).
 *
 * - wall_x:
 *     The exact X position on the wall hit, used for horizontal texture mapping.
 *
 * - line_height:
 *     The height of the vertical wall slice to draw, based on the wall distance.
 *
 * - draw_start / draw_end:
 *     The Y-coordinate range on screen where the vertical wall line will be drawn.
 *
 * - tex_x:
 *     The X coordinate in the texture that corresponds to the wall hit.
 *
 * - tex_pos:
 *     The initial Y position in the texture to start sampling from during rendering.
 *
 * - step:
 *     The amount to step in the texture per screen pixel (vertical) when rendering.
 */
typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	bool	has_hit_wall;
	int		side_hit;
	double	wall_dist;
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	tex_pos;
	double	step;
}	t_ray;

/* ########  MAIN STRUCT PART  ######## */
typedef struct s_cub {
	t_map					map;
	t_texture				north;
	t_texture				south;
	t_texture				east;
	t_texture				west;
	t_mlx					*mlx;
	t_surface_color			*surface_color;
	int						fd;
	int						line_counter;
	int						nb_of_line_in_file;
	bool					map_flag;
	char					*line;
	char					**elements_of_line;
	t_elements_of_parsing	type;
	t_elements_tracker		elements_tracker;
	int						map_first_line;
	int						map_last_line;
	size_t					map_line_counter;
	size_t					map_longest_line;
	bool					map_is_finished;
	int						nb_of_players;
	char					**map_to_check;
	int						x_coordinate_of_player;
	int						y_coordinate_of_player;
	t_player				*player;
	t_image					*image;
	int						screen_width;
	int						screen_height;
}	t_cub;

#endif
