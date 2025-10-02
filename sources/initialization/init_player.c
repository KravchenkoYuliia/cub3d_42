/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:01:52 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/02 17:52:08 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Finds and sets the initial position of the player on the map grid.
 *
 * This function scans the 2D map grid to locate the tile where the player is
 * placed,identified by one of the orientation characters: 'N', 'S', 'E', or 'W'
 * Once found, it sets the player's position (`pos_x`, `pos_y`) to the
 * **center** of the tile using the `TILE_CENTER_OFFSET` constant.
 *
 * The map is grid-based, where each tile is treated as a square of 1x1 units,
 * and the coordinate `(x, y)` refers to the **top-left corner** of a tile.
 * To avoid placing the player at the edge of the tile (which could cause
 * rendering or collision issues), we add `TILE_CENTER_OFFSET` (usually 0.5)
 * to center the player within the tile.
 *
 * Example:
 * - Tile at grid `[2][3]` (x=3, y=2)
 * - Player position becomes: `pos_x = 3.5`, `pos_y = 2.5`
 *
 * @param map Pointer to the map structure containing the grid.
 * @param player Pointer to the player structure whose position will be set.
 */
static void	ft_get_player_position(t_map *map, t_player *player)
{
	int	x;
	int	y;

	if (!map || !player)
		return ;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'N' || map->grid[y][x] == 'S'
				|| map->grid[y][x] == 'W' || map->grid[y][x] == 'E')
			{
				player->pos_x = x + TILE_CENTER_OFFSET;
				player->pos_y = y + TILE_CENTER_OFFSET;
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Initializes the player's direction and camera plane based on their
 *        starting orientation.
 *
 * This function reads the player’s starting orientation from the map grid
 * ('N', 'S', 'E', 'W') and converts it to a direction angle in radians.
 * It then uses trigonometric functions to compute the direction
 * vector (dir_x, dir_y) and the camera plane vector (plane_x, plane_y),
 * which is perpendicular to the direction.
 *
 * The angle is determined based on screen coordinate conventions:
 * - In screen space, the origin (0,0) is at the top-left corner.
 * - The X axis increases to the right, and the Y axis increases **downward**.
 *
 * Therefore, directions are interpreted as:
 * - 'N' (North / Up):       angle = -π/2  → (dir_x =  0, dir_y = -1)
 * - 'S' (South / Down):     angle =  π/2  → (dir_x =  0, dir_y = +1)
 * - 'W' (West  / Left):     angle =  π    → (dir_x = -1, dir_y =  0)
 * - 'E' (East  / Right):    angle =  0    → (dir_x = +1, dir_y =  0)
 *
 * The camera plane is calculated as a perpendicular vector to the direction,
 * scaled by the desired field of view using: plane = dir ⊥ * FOV_SCALE.
 *
 * @param map Pointer to the map structure containing the 2D grid.
 * @param player Pointer to the player structure to initialize.
 */
void	ft_get_player_direction(t_map *map, t_player *player)
{
	char	player;

	if (!map || !player)
		return ;
	player = map->grid[(int)player->pos_y][(int)player->pos_x];
	if (player == 'N')
		player->dir_angle = -(M_PI / 2);
	else if (player == 'W')
		player->dir_angle = M_PI;
	else if (player == 'S')
		player->dir_angle = M_PI / 2;
	else
		player->dir_angle = 0;
	player->dir_x = cos(player->dir_angle);
	player->dir_y = sin(player->dir_angle);
	player->plane_x = -player->dir_y * FOV_SCALE;
	player->plane_y = player->dir_x * FOV_SCALE;
}

t_player	*ft_init_player(t_cub *data)
{
	t_player	*player;

	if (!data)
		return (NULL);
	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	ft_get_player_position(data->map, player);
	ft_get_player_direction(data->map, player);
}
