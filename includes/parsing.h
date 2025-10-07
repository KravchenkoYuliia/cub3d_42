/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:03:08 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/07 16:03:38 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

void	ft_check_args(int ac, char **av);
void	ft_parsing(t_cub *cub, char *descriptional_file);
void	ft_reading_loop(t_cub *cub);
void	ft_handle_every_line(t_cub *cub);
bool	ft_this_is_texture(t_cub *cub);
void	ft_check_texture(t_cub *cub);
void	ft_check_rgb_colors(t_cub *cub);
void	ft_check_map(t_cub *cub);
void	ft_read_fd_till_the_end(int fd);
void	ft_choose_direction_if_texture(t_cub *cub);
void	ft_choose_surface_if_color(t_cub *cub);
void	ft_check_if_all_elements_are_in_file(t_cub *cub);
void	ft_fill_map_structure(t_cub *cub, char *descriptional_file);
void	ft_handle_spaces_in_map(t_cub *cub);
void	ft_replace_outside_spaces(t_cub *cub);
void	ft_replace_inside_spaces(t_cub *cub);
void	ft_path_finding(t_cub *cub);

#endif
