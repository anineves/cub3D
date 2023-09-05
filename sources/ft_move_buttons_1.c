/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:05:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/05 21:22:02 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_a(t_data *data)
{
	double new_x;
	double new_y;
	/*Verificar colisoes, implementei a funcao not_hit_wall
	esta a dar problemas devido ao valor de player->px*/
	new_x = data->player.px + data->player.dir_y * MOVESPEED;
	new_y = data->player.py - data->player.dir_x * MOVESPEED;
	printf("entrei no 97 %f %f\n", data->player.px, data->player.py);
	//data->player.px = new_x;
	//data->player.py = new_y;
	if(not_hit_wall(data, new_x, new_y))
	{
		data->player.px = new_x;
		data->player.py = new_y;
	}
	printf("entrei no 97 posicao x: %f posicao y:%f dir_x:%f dir_y:%f\n", data->player.px, data->player.py, data->player.dir_x, data->player.dir_y);
}

void	move_d(t_data *data)
{
	double new_x;
	double new_y;
	new_x = data->player.px - data->player.dir_y * MOVESPEED;
	new_y = data->player.py + data->player.dir_x * MOVESPEED;
	//data->player.px = new_x;
	//data->player.py = new_y;
	if(not_hit_wall(data, new_x, new_y))
	{
		data->player.px = new_x;
		data->player.py = new_y;
	}
	printf("entrei no 100 %f %f\n", data->player.px, data->player.py);
}

void	move_w(t_data *data)
{
	data->player.px += data->player.dir_x * MOVESPEED;
	data->player.py += data->player.dir_y * MOVESPEED;
	//return(not_hit_wall(data, new_x, new_y));
	//py-=1;
	//px+=pdx*5; 
	//py+=pdy*5;
	printf("entrei no 119 %f %f\n", data->player.px, data->player.py);
}

void	move_s(t_data *data)
{
	//py+=1;
	data->player.px -= data->player.dir_x * MOVESPEED;
	data->player.py -= data->player.dir_y * MOVESPEED;
	//return(not_hit_wall(data, new_x, new_y));
	//px-=pdx*5; 
	//py-=pdy*5;
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
}
