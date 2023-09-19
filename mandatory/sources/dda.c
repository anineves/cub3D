/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:44:39 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/14 16:33:25 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* A função dda é usada para calcular os valores iniciais 
necessários para traçar  de raio. 
o algoritmo calcula a direção do raio (dir_x e dir_y), 
determina a direção do passo (step_x e step_y), 
e calcula as distâncias laterais para o próximo lado (sidedist_x e sidedist_y)
 com base na posição do jogador e na direção do raio.*/
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
		ray->sidedist_x = (ray->map_x + 1.0f - player->px) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->py - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0f - player->py) * ray->deltadist_y;
	}
}
 /*
 Aplica o algoritmo DDA 
 para determinar as coordenadas onde o raio atinge um objeto no mapa.
 algoritmo DDA é aplicado em um loop enquanto hit for igual 0 
 O loop continua até que o raio atinja uma parede no mapa. Durante cada iteração do loop, 
 o algoritmo verifica se a próxima célula no mapa (ray->map_x e ray->map_y) é uma parede
 Se for uma parede, o loop termina indicando que o raio atingiu algo.
 O algoritmo escolhe qual direção (horizontal ou vertical) verificar primeiro com base nas distâncias laterais 
 (ray->sidedist_x e ray->sidedist_y).
 Atualiza as coordenadas do mapa e a lateral (ray->side) à medida que se move ao longo do raio.
*/
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
		if (data->map.full[ray->map_y][ray->map_x] == '1')
			hit = 1;
	}
}
