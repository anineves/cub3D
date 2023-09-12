/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:24:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 18:59:27 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->wall_dist = 0;
	ray->wall_x = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_map(t_map *map)
{
	map->full = NULL;
	map->file = NULL;
	map->file = NULL;
	map->len = 0;
	map->num_player = 0;
	map->north = NULL; 
	map->south = NULL;
	map->west = NULL;
	map->east= NULL;
	map->floor = -1;
	map->ceiling = -1;
	map->rows = 0;
	map->first_line = 0;
	map->pos = 0;
	map->step =0;
	map->size_tex = 64 ;
}


void	init_player(t_player *player)
{
	player->dir = 'S';
	player->px = 0;
	player->py = 0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_ad = 0;
	player->move_ws = 0;
	player->rotate = 0;
}



void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	init_map(&data->map);
	init_img_clean(&data->north_img);
	init_img_clean(&data->south_img);
	init_img_clean(&data->east_img);
	init_img_clean(&data->west_img);
	init_player(&data->player);
	init_ray(&data->ray);
	data->texture_pixels = NULL;
	data->textures = NULL;
}
