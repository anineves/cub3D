/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:05:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/07 21:55:53 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_a(t_data *data)
{
	double new_x;
	double new_y;
	new_x = data->player.px + data->player.dir_y * MOVESPEED;
	new_y = data->player.py - data->player.dir_x * MOVESPEED;
	printf("entrei no 97 %f %f\n", data->player.px, data->player.py);
	if(not_hit_wall(data, new_x - 4, new_y - 4))
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
	printf("entrei no 97 posicao x: %f posicao y:%f dir_x:%f dir_y:%f\n", data->player.px, data->player.py, data->player.dir_x, data->player.dir_y);
}

void	move_d(t_data *data)
{
	double new_x;
	double new_y;
	new_x = data->player.px - data->player.dir_y * MOVESPEED;
	new_y = data->player.py + data->player.dir_x * MOVESPEED;
	if(not_hit_wall(data, new_x - 4, new_y - 4))
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
	printf("entrei no 100 %f %f\n", data->player.px, data->player.py);
}

void	move_w(t_data *data)
{
	double new_x;
	double new_y;
	new_x = data->player.px + data->player.dir_x * MOVESPEED;
	new_y = data->player.py + data->player.dir_y * MOVESPEED;
	if(not_hit_wall(data, new_x - 4, new_y - 4))
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
	printf("entrei no 119 %f %f\n", data->player.px, data->player.py);
}

void	move_s(t_data *data)
{
	double new_x;
	double new_y;
	new_x = data->player.px - data->player.dir_x * MOVESPEED;
	new_y = data->player.py - data->player.dir_y * MOVESPEED;
	if(not_hit_wall(data, new_x - 4, new_y - 4))
	{
		data->player.px = new_x;
		data->player.py = new_y;
		data->player.has_moved = 1;
	}
	printf("entrei no 115 %f %f\n", data->player.px, data->player.py);
}

void	rotate_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player.dir_x;
	data->player.dir_x = (data->player.dir_x * cos(-rotSpeed)) \
							- (data->player.dir_y * sin(-rotSpeed));
	data->player.dir_y = olddirx * sin(-rotSpeed) + \
							data->player.dir_y * cos(-rotSpeed);
	oldplanex = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-rotSpeed) \
							- data->player.plane_y * sin(-rotSpeed);
	data->player.plane_y = oldplanex * sin(-rotSpeed) + \
							data->player.plane_y * cos(-rotSpeed);
	data->player.has_moved = 1;
}
