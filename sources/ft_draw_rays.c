/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:03:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/08 21:26:08 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)(player->px);
	ray->map_y = (int)(player->py);
	ray->deltadist_x = fabs(1/ ray->dir_x);
	ray->deltadist_y = fabs(1/ray->dir_y);
}

void	dda(t_ray *ray, t_player *player)
{
	
	if (ray->dir_x < 0) 
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->px - ray->map_x) * ray->deltadist_x;
		printf("Entrei , side %f \n", ray->sidedist_x);
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
			|| ray->map_y > data->map.rows *mapS - mapS/2
			|| ray->map_x > data->map.len *mapS - mapS/2)
			break ;
		else if (data->map.full[(ray->map_y - mapS/2)/mapS][(ray->map_x - mapS/2)/mapS] > '0')
			hit = 1;
	}
}

void calculate_per(t_data *data)
{
	if(data->ray.side == 0) 
		data->ray.wall_dist = (data->ray.sidedist_x - data->ray.deltadist_x);
    else          
		data->ray.wall_dist = (data->ray.sidedist_x - data->ray.deltadist_x);
}
/*

Codigo para o render
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -(ray->line_height) / 2 +WINDOW_HEIGHT/ 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT/ 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT- 1;
	if (ray->side == 0)
		ray->wall_x = player->py + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->px + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}


void	update_texture_pixels(t_data *data, t_map *tex, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	tex->x = (int)(ray->wall_x * tex->size);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		tex->x = tex->size - tex->x - 1;
	tex->step = 1.0 * tex->size / ray->line_height;
	tex->pos = (ray->draw_start - data->win_height / 2
			+ ray->line_height / 2) * tex->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex->y = (int)tex->pos & (tex->size - 1);
		tex->pos += tex->step;
		color = data->textures[tex->index][tex->size * tex->y + tex->x];
		if (tex->index == NORTH || tex->index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}   
*/
int	draw_rays2d(t_data *data)
{
	int	r;

	r = 0;
	
	while (r < WINDOW_WIDTH) //mudar valor
	{
		printf("entrei again\n");
		init_raycasting(r, &data->ray, &data->player);
		dda(&data->ray, &data->player);
		apply_dda(data, &data->ray);
		//calculate_line_height(&data->ray, data, &data->player);
		//update_texture_pixels(data, &data->map, &data->ray, r);
		/*draw_line(data->mlx_ptr, data->win_ptr, data->player.px, \
					data->player.py, data->player.dir_x  , \
					data->player.dir_y , 0x8B000);*/
		//calculate_per(data);>mlx_ptr, data->win_ptr
		draw_line(data, data->player.px, \
						data->player.py, data->player.px + data->player.dir_x * ((int)data->ray.sidedist_x + (int)data->ray.deltadist_x),\
						data->player.py + data->player.dir_y * 
						((int)data->ray.sidedist_y + (int)data->ray.deltadist_y), 0x008C00);
		printf(" valor ray x %f, valor ray y %f\n", data->ray.sidedist_x, data->ray.sidedist_y);
				r++;
	}
	return (1);
}