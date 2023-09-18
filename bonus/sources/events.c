/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:45:28 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/18 23:36:43 by anaraujo         ###   ########.fr       */
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
	if (key == SPACE)
		data->player.opendoor = 1;
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
	if (key == SPACE && data->player.opendoor == 1)
		data->player.opendoor = 0;
	return (0);
}

static void	mouse_position(t_data *data, int x, int y)
{
	if (x > WINDOW_WIDTH - 5)
	{
		x = 5;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
	if (x < 5)
	{
		x = WINDOW_WIDTH - 5;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, x, y);
	}
}

int	rotate_mouse(int x, int y, t_data *data)
{
	static int	old_x = WINDOW_WIDTH / 2;

	mouse_position(data, x, y);
	if (x == old_x)
		return (0);
	else if (x < old_x)
		rotate_left(data);
	else if (x > old_x)
		rotate_right(data);
	old_x = x;
	return (0);
}

int	mouse_input_release(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		data->clickmouse = 0;
	return (0);
}

int	mouse_input(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		data->clickmouse = 1;
	return (0);
}

/*void	events(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
				key_release_handler, data);
	mlx_hook(data->win_ptr, 04, 1L << 2, mouse_input, &data);
	mlx_hook(data->win_ptr, 05, 1L << 3, mouse_input_release, &data);
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, \
				mouse_menu_game, data);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, ft_close, data);
}*/

void	events(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, key_press_handler, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask, \
				key_release_handler, data);
	mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, \
				mouse_menu_game, data);
	mlx_hook(data->win_ptr, ClientMessage, NoEventMask, ft_close, data);
}
