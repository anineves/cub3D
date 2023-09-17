/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andreia <andreia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:36:41 by andreia           #+#    #+#             */
/*   Updated: 2023/09/17 19:01:45 by andreia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    menu(t_data *data)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.background.img, 0, 0);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.button_p.img, 380, 200);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->menu.button_q.img, 430, 400);
    if (data->menu.is_button_play)
    {
        data->menu.start_play = 1;
    }
    else if (data->menu.is_button_quit)
    {
        ft_close(data);
    } 
}