/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:29:13 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 18:22:24 by anaraujo         ###   ########.fr       */
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
		player->ang = 270;
	}
	else if (player->dir == 'N')
	{
		player->dir_x = 0.0f;
		player->dir_y = -1.0f;
		player->plane_x = 0.66;
		player->plane_y = 0;
		player->ang = 90;
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

/*void	init_images_player(t_data *data)
{
	data->player.img_player= ft_calloc(3, sizeof * data->player.img_player);
	//data->player.img_player = malloc(3 * sizeof(t_img *));
	//data->img.size_player = 5;
	data->player.img_player[0] = mlx_xpm_file_to_image(data->mlx_ptr, SWORD1,
			&(data->player.img_player[0]->size.x), &(data->player.img_player[0]->size.y));
	data->player.img_player[1] = mlx_xpm_file_to_image(data->mlx_ptr, SWORD2,
			&(data->player.img_player[1]->size.x), &(data->player.img_player[1]->size.y));
	data->player.img_player[2] = mlx_xpm_file_to_image(data->mlx_ptr, SWORD3,
			&(data->player.img_player[2]->size.x), &(data->player.img_player[2]->size.y));
}*/

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
