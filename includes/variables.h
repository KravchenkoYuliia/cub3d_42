/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:05:00 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/16 15:17:08 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

/* WINDOW SIZE */

# define WIN_WIDTH 2560
# define WIN_HEIGHT 1440
# define WIN_NAME "cub3d"
/* KEYBOARD KEY */

# define ESC_BUTTON 65307

/* DRAWING */

# define NUM_SURFACES 2 // Floor and Ceiling
# define RGB_SIZE 3
# define TILE_CENTER_OFFSET 0.5
# define PLANE_SCALE 0.66f
# define DEFAULT_MOVE_SPEED 0.05f
# define DEFAULT_ROTATE_SPEED 0.03f
# define SPACE ' '
# define OUTSIDE_SPACE '+'
# define NUM_OF_ELEMENTS_IN_FILE 7
# define BITS_PER_BYTE 8

#endif
