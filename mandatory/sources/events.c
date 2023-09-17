/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:45:28 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/17 09:04:26 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	key_press_handler(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	if (key == LEFT)
		data->player.rotate -= 1;
	if (key == RIGHT)
		data->player.rotate += 1;
	if (key == W)
		data->player.move_ws = 1;
	if (key == S)
		data->player.move_ws = -1;
	if (key == A)
		data->player.move_ad = -1;
	if (key == D)
		data->player.move_ad = 1;
	return (0);
}

static int	key_release_handler(int key, t_data *data)
{
	if (key == ESC)
		ft_close(data);
	if (key == W && data->player.move_ws == 1)
		data->player.move_ws = 0;
	if (key == S && data->player.move_ws == -1)
		data->player.move_ws = 0;
	if (key == A && data->player.move_ad == -1)
		data->player.move_ad = 0;
	if (key == D && data->player.move_ad == 1)
		data->player.move_ad = 0;
	if (key == LEFT && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == RIGHT && data->player.rotate >= -1)
		data->player.rotate = 0;
	return (0);
}

void	events(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
				key_release_handler, data);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, ft_close, data);
}
