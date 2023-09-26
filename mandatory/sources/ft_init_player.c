/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:29:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/26 17:48:16 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_info(t_data *data, int x, int y, char dir)
{
	data->player.px = (double)x + 0.5;
	data->player.py = (double)y + 0.5;
	data->player.dir = dir;
}

void	init_player_sn(t_player *player)
{
	if (player->dir == 'S')
	{
		player->dir_x = 0.0f;
		player->dir_y = 1.0f;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0.0f;
		player->dir_y = -1.0f;
		player->plane_x = 0.66;
		player->plane_y = 0;
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
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

void	init_player_direction(t_data *data)
{
	init_player_sn(&data->player);
	init_player_ew(&data->player);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, \
					"cub3d");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}
