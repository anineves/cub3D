/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:36:41 by andreia           #+#    #+#             */
/*   Updated: 2023/09/20 20:02:16 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	is_button_play(t_data *data, int x, int y)
{
	if (x > 900 && y > 400 && y < 400 + data->menu.button_p.size.y \
		&& x < 900 + data ->menu.button_p.size.x)
		data->menu.is_button_play = 1;
	else
		data->menu.is_button_play = 0;
}

void	is_button_quit(t_data *data, int x, int y)
{
	if (x > 900 && y > 550 && y < 550 + data->menu.button_q.size.y \
		&& x < 900 + data ->menu.button_q.size.x)
		data->menu.is_button_quit = 1;
	else
		data->menu.is_button_quit = 0;
}

int	init_menu_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx_ptr, path, \
		&image->size.x, &image->size.y);
	image->addr = (int *)mlx_get_data_addr(image->img, &image->pixel_bits,
			&image->size_line, &image->endian);
	return (1);
}

void	menu(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->menu.background.img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->menu.button_p.img, 900, 400);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
								data->menu.button_q.img, 900, 550);
	if (data->clickmouse == 1 && data->menu.is_button_play && \
			data->menu.start_play == 0)
		data->menu.start_play = 1;
	else if (data->clickmouse == 1 && data->menu.is_button_quit)
		ft_close(data);
}

int	render(t_data *data)
{
	if (data->menu.start_play == 0)
		menu(data);
	else
	{
		render_images(data);
		draw_map2d(data);
		buttons(data);
	}
	return (0);
}
