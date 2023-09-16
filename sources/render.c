/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:38:30 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/16 17:15:50 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//definir o valor de um pixel na imagem
void	fill_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

/*define os pixels na imagem. Verifica a cor do pixel em 
data->texture_pixels na posição (x, y),  e define o pixel 
correspondente na t_img image com essa cor.
Se existir textura nao definida (data->texture_pixels[y][x] == 0), 
usa data->map.c para o ceiling  e data->map.f para a parte floor).*/
static void	fill_image(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] != 0)
		fill_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < WINDOW_HEIGHT / 2)
		fill_pixel(image, x, y, data->map.c);
	else if (y < WINDOW_HEIGHT -1)
		fill_pixel(image, x, y, data->map.f);
}

/*cria uma imagem do tamanho W_W e W_H e preenche os pixels com a funcao 
set_frame_image_pixel */
static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;
	int		j;

	j = -1;
	image.img = NULL;
	init_img(data, &image, WINDOW_WIDTH, WINDOW_HEIGHT);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			fill_image(data, &image, x, y);
			x++;
		}
		y++;
	}
	while (data->texture_pixels[++j])
		free(data->texture_pixels[j]);
	free(data->texture_pixels);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.img);
}

/*Aloca memoria, para texture_pixels que vai armazenar o valor 
dos pixeis da textura durante o raycasting */
void	init_texture_pixels(t_data *data)
{
	int	i;

	data->texture_pixels = ft_calloc(WINDOW_HEIGHT + 1,
			sizeof * data->texture_pixels);
	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		data->texture_pixels[i] = ft_calloc(WINDOW_WIDTH + 1,
				sizeof * data->texture_pixels);
		i++;
	}
}

void	render_images(t_data *data)
{
	init_texture_pixels(data);
	raycasting(data);
	render_frame(data);
}
