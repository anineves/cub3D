/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:29:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 17:46:42 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player_sn(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0.0f;
		player->dir_y = 1.0f;
		player->plane_x = -0.66;
		player->plane_y = 0;
		player->ang = 270;
		printf("entrei\n");
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0.0f;
		player->dir_y = -1.0f;
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->ang = 90;
		printf("entrei N\n");
	}
	else
		return ;
}

static void	init_player_ew(t_player *player)
{
	if (player->dir == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
		player->ang = 180;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
		player->ang = 0;
	}
	else
		return ;
}

void	init_player_direction(t_data *data)
{

	init_player_sn(&data->player);
	init_player_ew(&data->player);
}
