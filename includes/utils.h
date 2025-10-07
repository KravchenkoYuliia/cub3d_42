/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:14:20 by jgossard          #+#    #+#             */
/*   Updated: 2025/10/07 16:43:30 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//UTILS

bool		ft_checking_nb_of_elements_in_array(char **array, int expected_nb);
void		ft_cut_new_line_at_the_end(char *line);
bool		ft_line_only_has_whitespaces(char *line);
bool		ft_check_file_extension(char *file_name, char *extension);
char		*ft_strcpy(char *dest, char *src);
bool		ft_line_has_no_1(char *line);
void		ft_open_descriptional_file(t_cub *cub, char *file);
char		**ft_copy_array_of_char(t_cub *cub);

// Memory

void		ft_fatal_error_in_parsing(char *msg, t_cub *cub);
void		ft_free_cub(t_cub *cub);
int			ft_free_all_and_exit(t_cub *cub);
void		ft_free_map(t_cub *cub);

#endif
