/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:27 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/02 18:42:45 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
    deltaX /= pixels; // 1
    deltaY /= pixels; // 0

    double pixelX = beginX;
    double pixelY = beginY;
    while (pixels)
    {
        mlx_pixel_put(mlx, win, pixelX, pixelY, color);
        pixelX += deltaX;
        pixelY += deltaY;
        --pixels;
    }
}

void draw_player(t_data *data, t_rect rect)
{
    int i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x00008B);
        ++i;
    }
}

int render_rect(t_data *data, t_rect rect, int x, int y)
{
    (void)x;
    (void)y;
    int	i;
    int j;

    if (data->win_ptr == NULL)
        return (1);
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, rect.color);
        ++i;
    }
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x + rect.width, rect.y, 0xFF8C00);
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x, rect.y + rect.height, 0xFF8C00);
    return (0);
}

int drawMap2D(t_data *data)
{
    int x;
    int y;
    int xo;
    int yo;

    y = 0;
    while (y < mapY)
    {
            x = 0;
            while (x < mapX)
            {
                xo = x*mapS;
                yo = y*mapS;
                if (data->map.full[y][x] == '1')
                    render_rect(data, (t_rect){xo, yo, mapS, mapS, GREEN_PIXEL}, x, y);
                else 
			   		render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL}, x, y);
                render_rect(data, (t_rect){(data->player.px),(data->player.py), 8, 8, 0x00008B}, x, y);
                draw_line(data->mlx_ptr, data->win_ptr, data->player.px + 4, data->player.py + 4, data->player.px + data->player.dir_x*10, data->player.py + data->player.dir_y*10, 0xFF8C00);
                x++;
            } 
            y++;
    }
    return (0);
}
