/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:24:44 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/09 16:24:42 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->ra =0;
	ray->camera_x = 0;
	ray->camera_y = 0;
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
	map->floor = 0;
	map->ceiling = 0;
	map->rows = 0;
	map->first_line = 0;
	map->pos = 0;
	map->step =0;
	map->size_tex = 64 ;
}

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1,
			sizeof * buffer * mapS * mapS);
	
	y = 0;
	while (y < mapS)
	{
		x = 0;
		while (x < mapS)
		{
			buffer[y * mapS + x]
				= tmp.addr[y * mapS + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	data->textures[NORTH] = xpm_to_img(data, data->map.north);
	
	data->textures[SOUTH] = xpm_to_img(data, data->map.south);
	data->textures[EAST] = xpm_to_img(data, data->map.east);
	data->textures[WEST] = xpm_to_img(data, data->map.west);
}

void	init_player(t_player *player)
{
	player->dir = 'S';
	player->px = 4 * mapS + mapS/2;
	player->py = 3 * mapS + mapS/2;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
	player->has_moved = 0;
	player->move_ad = 0;
	player->move_ws = 0;
	player->rotate = 0;
}

void	init_img_clean(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->pixel_bits = 0;
	img->size_line = 0;
	img->endian = 0;
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
	data->texture_pixels = NULL;
	data->textures = NULL;
}
