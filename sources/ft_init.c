/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:24:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/01 23:47:39 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->full=NULL;
}

void	init_player(t_player *player)
{
	player->dir = '\0';
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	//player->has_moved = 0;
	//player->move_x = 0;
	//player->move_y = 0;
	//player->rotate = 0;
}

void	init_data(t_data *data)
{
	data->mlx_ptr=NULL;
    data->win_ptr=NULL;
    init_map(&data->map);
    init_player(&data->player);
}