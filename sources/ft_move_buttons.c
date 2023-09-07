/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/07 23:04:31 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	not_hit_wall(t_data *data, double x, double y)
{
	int i = 0;
	printf("%d\n", (int)x/mapS);
	printf("%d\n", (int)y/mapS);
	printf("%c\n", data->map.full[((int)y/mapS)][((int)x/mapS)]);
	while (i < mapX )
	{
		printf("Map file %s\n", data->map.file[i]);
		printf("Map full %s\n", data->map.full[i]);
		i++;
	}
	if(data->map.full[((int)y/mapS)][((int)x/mapS)] == '0')
		return (1);
	return (0);
}

void	rotate_left(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rotSpeed) - \
							data->player.dir_y * sin(rotSpeed);
	data->player.dir_y = olddirx * sin(rotSpeed) + data->player.dir_y \
							* cos(rotSpeed);
	oldplanex = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rotSpeed) - \
							data->player.plane_y * sin(rotSpeed);
	data->player.plane_y = oldplanex * sin(rotSpeed) + data->player.plane_y \
							* cos(rotSpeed);
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
