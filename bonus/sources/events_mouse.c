/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:08:49 by andreia           #+#    #+#             */
/*   Updated: 2023/09/17 19:06:52 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void is_button_play(t_data *data, int x, int y)
{
    if (x > 380 && y >200 && y < 200 + data->menu.button_p.size.y \
        && x < 380 + data ->menu.button_p.size.x)
        data->menu.is_button_play = 1;
    else
        data->menu.is_button_play = 0;
}

void is_button_quit(t_data *data, int x, int y)
{
    if (x > 430 && y >400 && y < 400 + data->menu.button_q.size.y \
        && x < 430 + data ->menu.button_q.size.x)
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

int	mouse_menu(int x,int y, t_data *data)
{
	is_button_play(data, x, y);
	is_button_quit(data, x, y);
	if (data->menu.is_button_play)
    {
        init_menu_img(data, &data->menu.button_p, BUTTON1_SELECTED_XPM);
    }
	else
    {
        init_menu_img(data, &data->menu.button_p, BUTTON1_XPM);
    }
	if (data->menu.is_button_quit)
    {
        init_menu_img(data, &data->menu.button_q, BUTTON2_SELECTED_XPM);
	}
    else
    {
        init_menu_img(data, &data->menu.button_q, BUTTON2_XPM);
	}
    return (0);
}

int	mouse_menu_game(int x, int y, t_data *data)
{
	if (data->menu.start_play == 0)
		mouse_menu(x, y, data);
	else
		rotate_mouse(x, y, data);
	return (0);
}
