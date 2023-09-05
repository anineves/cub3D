/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/05 21:37:03 by andreia          ###   ########.fr       */
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
}

int	buttons(int key, t_data *data)
{
	if (key == 97)
		move_a(data);
	if (key == 100) 
		move_d(data); 
	if (key == 119)
		move_w(data);
	if (key == 115)
		move_s(data);
	if (key == XK_Right)
		rotate_right(data);
	if (key == XK_Left)
		rotate_left(data);
	if (key == XK_Escape)
	{
		printf("entrei no Escape");
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
		return (1);
	}
	return (0);
}
