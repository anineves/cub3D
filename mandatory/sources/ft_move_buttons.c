/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/17 08:59:15 by andreia          ###   ########.fr       */
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
	return (0);
}

int	render(t_data *data)
{
	buttons(data);
	render_images(data);
	return (0);
}
