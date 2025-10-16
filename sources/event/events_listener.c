/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_listener.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgossard <jgossard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:25:28 by yukravch          #+#    #+#             */
/*   Updated: 2025/10/15 18:36:31 by jgossard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_key_release(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape)
		ft_close_window(cub);
	else if (keycode == XK_w)
		cub->player->input.move_forward = false;
	else if (keycode == XK_s)
		cub->player->input.move_backward = false;
	else if (keycode == XK_a)
		cub->player->input.move_left = false;
	else if (keycode == XK_d)
		cub->player->input.move_right = false;
	else if (keycode == XK_Left)
		cub->player->input.camera_turn_left = false;
	else if (keycode == XK_Right)
		cub->player->input.camera_turn_right = false;
	return (0);
}

static int	ft_key_press(int keycode, t_cub *cub)
{
	if (keycode == XK_Escape)
		ft_close_window(cub);
	else if (keycode == XK_w)
		cub->player->input.move_forward = true;
	else if (keycode == XK_s)
		cub->player->input.move_backward = true;
	else if (keycode == XK_a)
		cub->player->input.move_left = true;
	else if (keycode == XK_d)
		cub->player->input.move_right = true;
	else if (keycode == XK_Left)
		cub->player->input.camera_turn_left = true;
	else if (keycode == XK_Right)
		cub->player->input.camera_turn_right = true;
	return (0);
}

void	ft_events_listener(t_cub *cub)
{
	if (!cub || !cub->mlx || !cub->mlx->win || !cub->mlx->ptr)
		return ;
	mlx_hook(cub->mlx->win, KeyPress, KeyPressMask, &ft_key_press, cub);
	mlx_hook(cub->mlx->win, KeyRelease, KeyReleaseMask, &ft_key_release, cub);
	mlx_hook(cub->mlx->win, DestroyNotify, KeyPressMask,
		&ft_close_window, cub);
	mlx_loop_hook(cub->mlx->ptr, ft_run_game, cub);
	mlx_loop(cub->mlx->ptr);
}
