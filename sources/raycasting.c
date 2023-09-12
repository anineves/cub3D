/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:03:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/09 16:32:33 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = ((2* x / (double)WINDOW_WIDTH) - 1);
	printf("ray camera x %f\n", ray->camera_x);
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	printf("plane x %f plane y %f\n", player->plane_x, player->plane_y);
	ray->map_x = (int)(player->px);
	ray->map_y = (int)(player->py);
	ray->deltadist_x = fabs(1/ ray->dir_x);
	ray->deltadist_y = fabs(1/ray->dir_y);
	printf("delta x %f delta y %f\n", ray->deltadist_x, ray->deltadist_y);
}



static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	(void)data;
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT/ 2;
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


/*void	calculate_pixel(t_data *data, t_ray *ray)
{
	if (!ray->side)
		ray->wall_x = (int)data->player.py + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = (int)data->player.py + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)mapS);
	if (!ray->side && ray->dir_x > 0)
		ray->tex_x = mapS - ray->tex_x - 1;
	if (ray->side && ray->dir_y < 0)
		ray->tex_x = mapS - ray->tex_x - 1;
	ray->step = 1.0 * mapS / ray->line_height;
	ray->tex_pos = (ray->draw_start - (WINDOW_HEIGHT / 2) + ray->line_height / 2)
		* ray->step;
}

void	put_pixel(t_img *img, int x, int y,
	unsigned int color)
{
	char	*dst;
	int *int_ptr;

	int_ptr = (int *)img->addr + (y * img->size_line + x * (img->pixel_bits / 8));
	dst = (char *)int_ptr;
	*(unsigned int *) dst = color;
}


static void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	int	y;

	y = -1;
	while (++y < ray->draw_start)
	{
		put_pixel(&data->text, x, y, data->map.ceiling);
	}
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos & (mapS - 1);
		ray->tex_pos += ray->step;
		put_pixel(&data->text, x, y, get_type_wall(data, ray));
		y += 1;
	}
	y = ray->draw_end;
	while (y < WINDOW_HEIGHT)
	{
		put_pixel(&data->text, x, y, data->map.floor);
		y += 1;
	}
}*/ 
static void	get_texture_index(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			data->map.tex_index = WEST;
		else
			data->map.tex_index = EAST;
	}
	else
	{
		if (ray->dir_y > 0)
			data->map.tex_index = SOUTH;
		else
			data->map.tex_index = NORTH;
	}
}

void	update_texture_pixels(t_data *data, t_map *map, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	
	map->tex_x = (int)(ray->wall_x * mapS);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		map->tex_x = mapS - map->tex_x - 1;
	map->step = 1.0 * mapS / ray->line_height;
	map->pos = (ray->draw_start - WINDOW_HEIGHT / 2
			+ ray->line_height / 2) * map->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		map->tex_y = (int)map->pos & (mapS - 1);
		map->pos += map->step;
		color = data->textures[map->tex_index][mapS * map->tex_y + map->tex_x];
		if (map->tex_index == NORTH || map->tex_index == EAST)
			color = (color >> 1) & 8355711;
		if (color > 0)
			data->texture_pixels[y][x] = color;
		y++;
	}
}   


int	raycasting(t_data *data)
{
	int	r;

	r = 0;
	
	while (r <WINDOW_WIDTH) //mudar valor
	{
		//printf("entrei again\n");
		init_raycasting(r, &data->ray, &data->player);
		dda(&data->ray, &data->player);
		apply_dda(data, &data->ray);
		calculate_line_height(&data->ray, data, &data->player);
		update_texture_pixels(data, &data->map, &data->ray, r);
		//calculate_pixel(data, &data->ray);
		//draw_vertical_line(data, &data->ray, r);
		r++;
	}
	return (1);
}