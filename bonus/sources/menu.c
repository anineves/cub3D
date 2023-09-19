/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:36:41 by andreia           #+#    #+#             */
/*   Updated: 2023/09/19 18:39:34 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	*dst;

	if (color == (int)TRANSPARENCY)
		return ;
	dst = img->addr + (y * img->size_line + x * (img->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)((img.addr
			+ (y * img.size_line) + (x * img.pixel_bits / 8))));
}

void	render_rect_g(t_img *dst, t_img src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.size.y)
	{
		j = 0;
		while (j < src.size.x)
		{
			my_mlx_pixel_put(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}

void    menu(t_data *data)
{
    /*mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.background.img, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.button_p.img, 900, 400);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.button_q.img, 900, 550);*/
    if (data->clickmouse == 1 && data->menu.is_button_play && data->menu.start_play == 0)
    {
        data->menu.start_play = 1;
    }
    else if (data->clickmouse == 1 && data->menu.is_button_quit)
    {
        ft_close(data);
    } 
}