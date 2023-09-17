/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:53:59 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 18:52:08 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*cria uma nova imagem vazia com as dimensões fornecidas usando mlx_new_image 
e obtém informações sobre a imagem usando mlx_get_data*/
void	init_img(t_data *data, t_img *image, int width, int height)
{
	init_img_clean(image);
	image->img = mlx_new_image(data->mlx_ptr, width, height);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

t_img	ft_init_img(t_data *data)
{
	t_img	image;

	init_img_clean(&image);
	image.img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	image.addr = (int *)mlx_get_data_addr(image.img, &image.pixel_bits,
			&image.size_line, &image.endian);
	return (image);
}

/*inicia uma estrutura t_img para uma textura.  mlx_xpm_file_to_image carrega 
a imagem do ficheiro XPM  mlx_get_data_addr obtem informações sobre a imagem*/
int	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, \
					&data->map.size_tex, &data->map.size_tex);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	if (image->pixel_bits != 32 || image->size_line != 256)
		return (0);
	return (1);
}

/*carrega a textura XPM em uma estrutrura t_img, retorna o bffer que representa 
os pixels da textura*/
static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	y = -1;
	buffer = ft_calloc(1,
			sizeof * buffer * MAPS * MAPS);
	if (!init_texture_img(data, &tmp, path))
	{
		mlx_destroy_image(data->mlx_ptr, tmp.img);
		free(buffer);
		ft_error("size", data, 1);
	}
	while (++y < MAPS)
	{
		x = -1;
		while (++x < MAPS)
		{
			buffer[y * MAPS + x]
				= tmp.addr[y * MAPS + x];
		}
	}
	mlx_destroy_image(data->mlx_ptr, tmp.img);
	return (buffer);
}

void	init_textures(t_data *data)
{
	data->textures = ft_calloc(4, sizeof * data->textures);
	data->textures[NORTH] = xpm_to_img(data, data->map.north);
	data->textures[SOUTH] = xpm_to_img(data, data->map.south);
	data->textures[EAST] = xpm_to_img(data, data->map.east);
	data->textures[WEST] = xpm_to_img(data, data->map.west);
}