/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:03:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/18 23:04:42 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_raycasting(int x, t_ray *ray, t_player *player)
{
	init_ray(ray);
	ray->camera_x = ((2 * x / (double)WINDOW_WIDTH) - 1);
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->map_x = (int)(player->px);
	ray->map_y = (int)(player->py);
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->deltadist_y = fabs(1 / ray->dir_y);
}

/*calcula a altura da linha da parede que será desenhada. 
usa ray->wall_dist para determinar a altura da linha. 
calcula os pontos de início (ray->draw_start) e fim 
(ray->draw_end) da linha a ser desenhada.*/
static void	calculate_line_height(t_ray *ray, t_data *data, t_player *player)
{
	(void)data;
	if (ray->side == 0)
		ray->wall_dist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->wall_dist = (ray->sidedist_y - ray->deltadist_y);
	ray->line_height = (int)(WINDOW_HEIGHT / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WINDOW_HEIGHT / 2;
	if (ray->draw_end >= WINDOW_HEIGHT)
		ray->draw_end = WINDOW_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->py + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = player->px + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

/*determina qual textura deve ser usada para renderizar a parede com 
base na direção em que o raio está indo. verifica se o raio atinge uma 
parede vertical ou horizontal (ray->side) e também verifica a direção do raio 
(ray->dir_x e ray->dir_y) para determinar qual textura deve ser aplicada.*/
static void	get_texture_index(t_data *data, t_ray *ray)
{
	printf("posicap x %d, posicao y %d , char %c \n" , data->ray.map_x, data->ray.map_y, data->map.full[12][1]);
	if(data->map.full[data->ray.map_y][data->ray.map_x] == '1')
	{
		if (ray->side == 0 )
		{
			if (ray->dir_x < 0)
				data->map.tex_index = WEST;
			else
				data->map.tex_index = EAST;
		}
		else
		{
			if (ray->dir_y > 0 )
				data->map.tex_index = SOUTH;
			else
				data->map.tex_index = NORTH;
		}
	}
	else if(data->map.full[data->ray.map_y][data->ray.map_x] == 'C')
		data->map.tex_index = COIN;
}

/* atualiza o array data->texture_pixels.
calcula a posição (map->pos) na textura que deve ser mostrada para cada pixel 
na linha da parede. Obtém o valor de cor da textura na posição calculada e  
armazena na matriz data->texture_pixels. Antes de armazenar a cor, 
verifica se a textura e aplica um deslocamento de cor para tornar a 
renderização mais suave. Se a cor for maior que zero, ela é armazenada 
na matriz data->texture_pixels.
*/
void	update_texture_pixels(t_data *data, t_map *map, t_ray *ray, int x)
{
	int			y;
	int			color;

	get_texture_index(data, ray);
	map->tex_x = (int)(ray->wall_x * MAPS);
	if ((ray->side == 0 && ray->dir_x < 0)
		|| (ray->side == 1 && ray->dir_y > 0))
		map->tex_x = MAPS - map->tex_x - 1;
	map->step = 1.0 * MAPS / ray->line_height;
	map->pos = (ray->draw_start - WINDOW_HEIGHT / 2
			+ ray->line_height / 2) * map->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		map->tex_y = (int)map->pos & (MAPS - 1);
		map->pos += map->step;
		color = data->textures[map->tex_index][MAPS * map->tex_y + map->tex_x];
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
	while (r < WINDOW_WIDTH)
	{
		init_raycasting(r, &data->ray, &data->player);
		dda(&data->ray, &data->player);
		apply_dda(data, &data->ray);
		calculate_line_height(&data->ray, data, &data->player);
		update_texture_pixels(data, &data->map, &data->ray, r);
		r++;
	}
	return (1);
}
