/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:45:28 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/09 16:07:05 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int ft_close(t_data *data)
{
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
    return (0);
}


static int	key_press_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	if (key == XK_Left)
		data->player.rotate -= 1;
	if (key == XK_Right)
		data->player.rotate += 1;
	if (key == XK_w)
		data->player.move_ws = 1;
	if (key == XK_s)
		data->player.move_ws = -1;
	if (key == XK_a)
		data->player.move_ad = -1;
	if (key == XK_d)
		data->player.move_ad = 1;
	return (0);
}
static int	key_release_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		ft_close(data);
	if (key == XK_w && data->player.move_ws == 1)
		data->player.move_ws = 0;
	if (key == XK_s && data->player.move_ws == -1)
		data->player.move_ws = 0;
	if (key == XK_a && data->player.move_ad == -1)
		data->player.move_ad = 0;
	if (key == XK_d && data->player.move_ad == 1)
		data->player.move_ad = 0;
	if (key == XK_Left && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == XK_Right && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}


void events(t_data *data)
{
    mlx_hook(data->win_ptr, ClientMessage, NoEventMask, ft_close, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, key_release_handler, data);
    mlx_loop_hook(data->mlx_ptr, &render, &data);
    //mlx_loop_hook(data.mlx_ptr, &draw_rays2d_1, &data);
    mlx_loop(data->mlx_ptr);
}