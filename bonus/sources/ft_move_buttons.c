/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 18:35:59 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-ROTSPEED) - \
							data->player.dir_y * sin(-ROTSPEED);
	data->player.dir_y = olddirx * sin(-ROTSPEED) + data->player.dir_y \
							* cos(-ROTSPEED);
	oldplanex = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-ROTSPEED) - \
							data->player.plane_y * sin(-ROTSPEED);
	data->player.plane_y = oldplanex * sin(-ROTSPEED) + data->player.plane_y \
							* cos(-ROTSPEED);
	data->player.has_moved = 1;
}

void	opendoor_1(t_data *data)
{
	int	x;
	int	y;

	y = data->player.py;
	x = data->player.px;
	if (data->player.dir_y >= 0 && data->map.full[y][x - 1] == 'D')
	{
		data->map.full[(int)data->player.py][(int)data->player.px - 1] = '0';
		data->map.door.x = x - 1;
		data->map.door.y = y;
	}
	if (data->player.dir_y <= 0 && data->map.full[y][x + 1] == 'D')
	{
		data->map.door.x = x + 1;
		data->map.door.y = y;
		data->map.full[(int)data->player.py][(int)data->player.px + 1] = '0';
	}
}

void	opendoor(t_data *data)
{
	int	x;
	int	y;

	y = data->player.py;
	x = data->player.px;
	if (data->player.dir_y < 0 && data->map.full[y - 1][x] == 'D')
	{
		data->map.full[(int)data->player.py - 1][(int)data->player.px] = '0';
		data->map.door.x = x;
		data->map.door.y = y - 1;
	}
	if (data->player.dir_y > 0 && data->map.full[y + 1][x] == 'D')
	{
		data->map.full[(int)data->player.py + 1][(int)data->player.px] = '0';
		data->map.door.x = x;
		data->map.door.y = y + 1;
	}
	opendoor_1(data);
}

void	close_door(t_data *data)
{
	if ((int)data->player.px != data->map.door.x \
		&& (int)data->player.py != data->map.door.y)
		data->map.full[data->map.door.y][data->map.door.x] = 'D';
}

int	buttons(t_data *data)
{
	data->player.has_moved = 0;
	if (data->map.is_door)
		close_door(data);
	if (data->player.move_ad == -1)
		move_a(data);
	if (data->player.move_ad == 1) 
		move_d(data); 
	if (data->player.move_ws == 1)
		move_w(data);
	if (data->player.move_ws == -1)
		move_s(data);
	if (data->player.rotate == 1)
		rotate_right(data);
	if (data->player.rotate == -1)
		rotate_left(data);
	if (data->map.is_door)
	{
		if (data->player.opendoor == 1)
			opendoor(data);
	}
	return (0);
}
