/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:15:55 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/03 16:28:20 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define NB_OF_ARGS "Error\nPut one argument\n"
# define WRONG_ARGV "Error\nCan't be a scene description file\n"
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
# define EMPTY_LINE_IN_MAP "Error\nEmpty line in map\n"
# define INVALID_MAP "Error\nMap is invalid\n"
# define INVALID_CHAR_IN_MAP "Error\nMap only can have 1, 0, N, S, E, W, space\n"
# define ONE_PLAYER "Error\nWrong number of players\n"

#endif
