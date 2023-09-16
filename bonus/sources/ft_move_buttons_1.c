/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:05:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 18:51:46 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_a(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.px + data->player.dir_y * MOVESPEED;
	new_y = data->player.py - data->player.dir_x * MOVESPEED;
	if (data->map.full[(int)new_y][(int)new_x] == '0')
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
}

void	move_d(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.px - data->player.dir_y * MOVESPEED;
	new_y = data->player.py + data->player.dir_x * MOVESPEED;
	if (data->map.full[(int)new_y][(int)new_x] == '0')
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
}

void	move_w(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.px + data->player.dir_x * MOVESPEED;
	new_y = data->player.py + data->player.dir_y * MOVESPEED;
	if (data->map.full[(int)new_y][(int)new_x] == '0')
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
}

void	move_s(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.px - data->player.dir_x * MOVESPEED;
	new_y = data->player.py - data->player.dir_y * MOVESPEED;
	if (data->map.full[(int)new_y][(int)new_x] == '0')
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
}

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player.dir_x;
	data->player.dir_x = (data->player.dir_x * cos(ROTSPEED)) \
							- (data->player.dir_y * sin(ROTSPEED));
	data->player.dir_y = olddirx * sin(ROTSPEED) + \
							data->player.dir_y * cos(ROTSPEED);
	oldplanex = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(ROTSPEED) \
							- data->player.plane_y * sin(ROTSPEED);
	data->player.plane_y = oldplanex * sin(ROTSPEED) + \
							data->player.plane_y * cos(ROTSPEED);
	data->player.has_moved = 1;
}
