/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:43:09 by yukravch          #+#    #+#             */
/*   Updated: 2025/09/29 17:21:23 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_isdigit_check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

static void	ft_loop_for_every_nb(t_cub *cub, char **rgb)
{
	int	i;

	i = 0;
	while (rgb[i])
	{
		if (rgb[i][0] && rgb[i][1] && rgb[i][2] && rgb[i][3])
		{
			ft_free_char_tab(rgb);
			ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
		}
		if (ft_isdigit_check_str(rgb[i]) == false)
		{
			ft_free_char_tab(rgb);
			ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
		}
		if (ft_atol(rgb[i]) > 255 || ft_atol(rgb[i]) < 0)
		{
			ft_free_char_tab(rgb);
			ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
		}
		i++;
	}
}

static void	ft_check_numbers(t_cub *cub)
{
	char	**rgb;

	rgb = ft_split(cub->elements_of_line[1], ',');
	if (!rgb)
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
	if (ft_checking_nb_of_elements_in_array(rgb, 3) == false)
	{
		ft_free_char_tab(rgb);
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
	}
	ft_loop_for_every_nb(cub, rgb);
	ft_free_char_tab(rgb);
}

static void	ft_check_commas(t_cub *cub)
{
	int		i;
	int		nb_of_commas;
	int		len;
	char	*rgb;

	i = 0;
	nb_of_commas = 0;
	len = ft_strlen(cub->elements_of_line[1]);
	rgb = cub->elements_of_line[1];
	if (rgb[0] == ',' || rgb[len - 1] == ',')
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
	while (rgb[i])
	{
		if (rgb[i] == ',')
		{
			if (rgb[i + 1] && rgb[i + 1] == ',')
				ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
			nb_of_commas++;
		}
		i++;
	}
	if (nb_of_commas != 2)
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
}

void	ft_check_rgb_colors(t_cub *cub)
{
	if (!cub)
		exit(EXIT_FAILURE);
	if (!cub->elements_of_line)
		ft_error_msg_free_exit(NULL, cub);
	if (cub->map_flag == true)
		ft_error_msg_free_exit(MAP_PLACING, cub);
	//must be 2: 1)F/C     2)12,12,12     3)NULL
	if (ft_checking_nb_of_elements_in_array(cub->elements_of_line, 2) == false)
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
	if (cub->elements_of_line[0][1]) //only 1 letter 'C' or 'F'
		ft_error_msg_free_exit(WRONG_COLOR_FORMAT, cub);
	ft_check_commas(cub);
	ft_check_numbers(cub);
}
