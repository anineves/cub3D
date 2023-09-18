/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 00:13:32 by anaraujo         ###   ########.fr       */
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

/*verificar se na proxima posicao temos uma porta*/
int	check_next_positions(t_data *data, char character_next_position)
{
	int	y;
	int	x;

	y = data->player.py;
	x = data->player.px;
	if ((data->player.dir_y < 0 && data->map.full[y - 1][x] == character_next_position)
		|| (data->player.dir_y > 0 && data->map.full[y + 1][x] == character_next_position)
		|| (data->player.dir_x < 0 && data->map.full[y][x - 1] == character_next_position)
		|| (data->player.dir_x > 0 && data->map.full[y][x + 1] == character_next_position))
		return (1);
	return (0);
}

void	opendoor(t_data *data)
{
	int	previous_y;
	int	previous_x;

	if (check_next_positions(data, 'D'))
	{
		if (data->player.dir_y < 0)
		{
			data->map.full[(int)data->player.py - 1][(int)data->player.px] = '0';
			previous_y = data->player.py - 1;
			previous_x = data->player.px;
		}
		else if (data->player.dir_y > 0)
		{
			data->map.full[(int)data->player.py + 1][(int)data->player.px] = '0';
			previous_y = data->player.py + 1;
			previous_x = data->player.px;
		}
		else if (data->player.dir_x < 0)
		{
			data->map.full[(int)data->player.py][(int)data->player.px - 1] = '0';
			previous_y = data->player.py;
			previous_x = data->player.px - 1;
		}
		else if (data->player.dir_x > 0)
		{
			data->map.full[(int)data->player.py][(int)data->player.px + 1] = '0';
			previous_y = data->player.py;
			previous_x = data->player.px + 1;
		}
	}
}

int	buttons(t_data *data)
{
	data->player.has_moved = 0;
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
	if (data->player.opendoor == 1)
		opendoor(data);
	return (0);
}
