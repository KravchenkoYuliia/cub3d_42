/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 18:14:27 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/26 17:18:32 by jgossard         ###   ########.fr       */
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
	BUT_W,
	BUT_A,
	BUT_S,
	BUT_D,
	BUT_LEFT,
	BUT_RIGHT,
}	t_button;

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

/* ########  TEXTURE STRUCT PART  ######## */

typedef struct s_texture_image
{
	void	*img;
	char	*data;      // pixel buffer (int per pixel)
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_texture_image;

typedef struct s_texture
{
	t_direction			direction;
	char				*path;
	t_texture_image		image;
}	t_texture;

/* ########  MLX STRUCT PART  ######## */

typedef struct s_mlx {
	void	*ptr;
	void	*win;
	// void	*img; // move to its own structure
}	t_mlx;

/* ########  MAP STRUCT PART  ######## */

typedef struct s_map {
	t_point	**grid; // grid[Y][x]
	int		map_width;
	int		map_height;
}	t_map;

/* ########  PLAYER STRUCT PART  ######## */

typedef struct s_player {
	// Player position on the map
	double	pos_x;
	double	pos_y;
	// Player direction vector on the map
	double	dir_x;
	double	dir_y;
	// 2D Camera plane
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rotate_speed;
}	t_player;

/* ########  IMAGE + RENDERING + RAYCASTING STRUCT PART  ######## */

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_image;


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

typedef struct s_draw {
	// height of line to draw
	int		line_height;
	// lowest pixel of wall
	int		draw_start;
	// highest pixel of wall
	int		draw_end;
	// x coordinate of texture
	int		tex_x;
	// starting texture position
	double	tex_pos;
	// how much to increase tex_pos per screen pixel
	double	step;
}	t_draw;


/* ########  MAIN STRUCT PART  ######## */
typedef struct s_cub {
	/* ########  PARSING / MAP DATA  ######## */
	t_map			*map;
	t_texture		*texture;
	t_surface_color	*surface_color;
	/* ########  PLAYER DATA  ######## */
	t_player		*player;
	/* ########  MLX CONTEXT  ######## */
	t_mlx			*mlx;
	/* ########  FRAME BUFFER (off-screen image) ######## */
	t_image			frame;
	/* ########  WINDOW / SCREEN INFO ######## */
	int				screen_width;
	int				screen_height;
	/* ########  PARSING HELPERS ######## */
	int				fd;
	bool			map_flag;
	char			*line;
	char			**elements_of_line;
}	t_cub;


#endif
