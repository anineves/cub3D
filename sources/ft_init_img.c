/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:53:59 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 19:58:51 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	y = 0;
	buffer = ft_calloc(1,
			sizeof * buffer * mapS * mapS);
	init_texture_img(data, &tmp, path);
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

void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, \
					&data->map.size_tex, &data->map.size_tex);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return ;
}

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
