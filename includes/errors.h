/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:15:55 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 14:54:23 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

/* Arguments */

# define NB_OF_ARGS "Error\nPut one argument\n"
# define WRONG_ARGV "Error\nCan't be a scene description file\n"

/* Parsing */

# define INVALID_FILE "Error\nInvalid scene description file.cub\n"
# define CANT_OPEN "Error\nCan't open a scene description file.cub\n"
# define EMPTY_FILE "Error\nThe file.cub is empty\n"
# define WRONG_TEXTURE "Error\nWrong texture format for map\n"
# define WRONG_PATH_TEXTURE "Error\nWrong path to texture\n"
# define WRONG_EXTENSION "Error\nWrong extension for file with texture\n"
# define MAP_PLACING "Error\nMap has to be placed at the end of a file\n"
# define WRONG_COLOR_FORMAT "Error\nWrong color format for map\n"
# define DOUBLE_ELEMENT "Error\nOne or more elements are twice in file.cub\n"
# define ELEMENT_MISSING "Error\nOne or more elements are missing in file.cub\n"
# define INVALID_COLOR "Error\nInvalid RGB color format or value\n"
# define EMPTY_LINE_IN_MAP "Error\nEmpty line in map\n"
# define INVALID_MAP "Error\nMap is invalid\n"
# define INVALID_CHAR_IN_MAP "Error\nMap only can have 1, 0, N, S, E, W, space\n"

/* Player */

# define ONE_PLAYER "Error\nWrong number of players\n"
# define PLAYER_OUT "Error\nPlayer is outside of map. Map is not closed\n"
# define ERR_PLAYER_POSITION "Error\nFailed to get player position\n"
# define ERR_PLAYER_DIRECTION "Error\nFailed to get player direction\n"
# define ERR_INIT_PLAYER "Error\nFailed to initialize player\n"

/* Texture*/

# define ERR_TEXTURE_LOAD "Error\nFailed to load texture file\n"
# define ERR_TEXTURE_ADDR "Error\nFailed to get texture data address\n"

#endif
