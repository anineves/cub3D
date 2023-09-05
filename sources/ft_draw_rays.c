/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:03:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/05 22:58:59 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->ra = FixAng(player->ang);
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1; //Mudar o valor
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_y;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)player->px/64;
	ray->map_y = (int)player->py/64;
	ray->deltadist_x = fabs(1/ ray->dir_x);
	ray->deltadist_y = fabs(1/ray->dir_y);
}

void	dda(t_ray *ray, t_player *player)
{
	
	if (ray->dir_x < 0) 
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->px - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->px) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->py - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->py) * ray->deltadist_y;
	}
}

void	apply_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_y < 0.25
			|| ray->map_x < 0.25
			|| ray->map_y > WINDOW_HEIGHT - 0.25
			|| ray->map_x > WINDOW_WIDTH - 1.25)
			break ;
		else if (data->map.full[ray->map_y][ray->map_x] > '0')
			hit = 1;
	}
}

int	draw_rays2d(t_data *data)
{
	(void) data;
	int	r;

	r = -19;
	
	while (r < 20) //mudar valor
	{
		printf("entrei again\n");
		init_raycasting(r, &data->ray, &data->player);
		dda(&data->ray, &data->player);
		apply_dda(data, &data->ray);
		draw_line(data->mlx_ptr, data->win_ptr, data->player.px, \
					data->player.py, data->ray.sidedist_x, \
					data->ray.sidedist_y, 0x8B000);
		r++;
	}
	return (1);
}