/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:38:30 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/12 22:43:21 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_image_pixel(t_img *image, int x, int y, int color)
{
	int	pixel;

	pixel = y * (image->size_line / 4) + x;
	image->addr[pixel] = color;
}

static void	set_frame_image_pixel(t_data *data, t_img *image, int x, int y)
{
	if (data->texture_pixels[y][x] > 0)
		set_image_pixel(image, x, y, data->texture_pixels[y][x]);
	else if (y < WINDOW_HEIGHT / 2)
		set_image_pixel(image, x, y, data->map.c);
	else if (y < WINDOW_HEIGHT -1)
		set_image_pixel(image, x, y, data->map.f);
}

static void	render_frame(t_data *data)
{
	t_img	image;
	int		x;
	int		y;

	image.img = NULL;
	init_img(data, &image, WINDOW_WIDTH, WINDOW_HEIGHT);
	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			set_frame_image_pixel(data, &image, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, image.img, 0, 0);
	mlx_destroy_image(data->mlx_ptr, image.img);
}

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
	///init_ray(&data->ray);
	raycasting(data);
	render_frame(data);
}

int	render(t_data *data)
{
	buttons(data);
	if (data->player.has_moved == 0)
		return (0);
	render_images(data);
	draw_map2d(data);
	return (0);
}

/*int render_mini(t_data *data)
{
    buttons(data);
    if(data->player.has_moved == 0)
        return (0);
    draw_map2d(data);
    return(0);
}*/
