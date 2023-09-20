/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:53:59 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 20:03:39 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	finish(t_data *data)
{
	printf("Error\nWrong size\n");
	ft_close(data);
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
		finish(data);
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

static void	init_menu_textures(t_data *data)
{
	data->menu.background.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	BACKGROUND, &data->menu.background.size.x, &data->menu.background.size.y);
	data->menu.button_p.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	BUTTON1_XPM, &data->menu.button_p.size.x, &data->menu.button_p.size.y);
	data->menu.button_q.img = mlx_xpm_file_to_image(data->mlx_ptr, \
	BUTTON2_XPM, &data->menu.button_q.size.x, &data->menu.button_q.size.y);
	data->menu.background.addr = (int *) \
	mlx_get_data_addr(data->menu.background.img, \
	&data->menu.background.pixel_bits, &data->menu.background.size_line, \
	&data->menu.background.endian);
	data->menu.button_p.addr = (int *) \
	mlx_get_data_addr(data->menu.button_p.img, \
	&data->menu.button_p.pixel_bits, &data->menu.button_p.size_line, \
	&data->menu.button_p.endian);
	data->menu.button_q.addr = (int *) \
	mlx_get_data_addr(data->menu.button_q.img, \
	&data->menu.button_q.pixel_bits, &data->menu.button_q.size_line, \
	&data->menu.button_q.endian);
}

void	init_textures(t_data *data)
{
	init_menu_textures(data);
	data->textures = ft_calloc(7, sizeof * data->textures);
	data->textures[NORTH] = xpm_to_img(data, data->map.north);
	data->textures[SOUTH] = xpm_to_img(data, data->map.south);
	data->textures[EAST] = xpm_to_img(data, data->map.east);
	data->textures[WEST] = xpm_to_img(data, data->map.west);
	data->textures[COIN] = xpm_to_img(data, PCOIN);
	data->textures[COIN1] = xpm_to_img(data, PCOIN1);
	data->textures[DOOR] = xpm_to_img(data, PDOOR);
}
