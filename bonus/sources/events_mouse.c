/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:08:49 by andreia           #+#    #+#             */
/*   Updated: 2023/09/19 23:01:47 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

int	mouse_menu_game(int x, int y, t_data *data)
{
	if (data->menu.start_play == 0)
		mouse_menu(x, y, data);
	else
		rotate_mouse(x, y, data);
	return (0);
}

void	ft_button_quit(t_data *data)
{
	if (data->menu.is_button_quit)
	{
		if (data->menu.button_q.img)
			mlx_destroy_image(data->mlx_ptr, data->menu.button_q.img);
		init_menu_img(data, &data->menu.button_q, BUTTON2_SELECTED_XPM);
	}
	else
	{
		if (data->menu.button_q.img)
			mlx_destroy_image(data->mlx_ptr, data->menu.button_q.img);
		init_menu_img(data, &data->menu.button_q, BUTTON2_XPM);
	}
}

int	mouse_menu(int x, int y, t_data *data)
{
	is_button_play(data, x, y);
	is_button_quit(data, x, y);
	if (data->menu.is_button_play)
	{
		if (data->menu.button_p.img)
			mlx_destroy_image(data->mlx_ptr, data->menu.button_p.img);
		init_menu_img(data, &data->menu.button_p, BUTTON1_SELECTED_XPM);
	}
	else
	{
		if (data->menu.button_p.img)
			mlx_destroy_image(data->mlx_ptr, data->menu.button_p.img);
		init_menu_img(data, &data->menu.button_p, BUTTON1_XPM);
	}
	ft_button_quit(data);
	return (0);
}
