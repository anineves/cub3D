/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:39:44 by andreia           #+#    #+#             */
/*   Updated: 2023/09/20 17:04:17 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_menu(t_menu *menu)
{
	menu->start_play = 0;
	menu->is_button_play = 0;
	menu->is_button_quit = 0;
}

void	init_doors(t_door *door)
{
	door->is_open = 0;
}

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
