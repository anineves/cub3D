/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:27 by anaraujo          #+#    #+#             */
/*   Updated: 2023/08/31 22:50:53 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
    double deltaX = endX - beginX;
    double deltaY = endY - beginY;

    int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
//  pixels = sqrt((10 * 10) + (0 * 0)) = sqrt(100) = 10
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

    /*i = rect.y  + 3*(rect.height/8);
        while (i < rect.y + 5*(rect.height/8))
        {
            j = rect.x + 3*(rect.width/8);
            while (j < rect.x + 5*(rect.width/8))
                mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x00008B);
            ++i;
        }
    */
    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, i, 0x00008B);
        ++i;
    }
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x + rect.width, rect.y, 0xFF8C00);
    draw_line(data->mlx_ptr, data->win_ptr, rect.x, rect.y, rect.x, rect.y + rect.height, 0xFF8C00);

}

int render_rect(t_data *data, t_rect rect, int x, int y)
{
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
    if (data->map.full[y][x] == '2')
    {
        draw_player(data, rect);
    }
    return (0);
}


/*int	render(t_data *data)
{
    render_rect(data, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
            100, 100, GREEN_PIXEL});
    render_rect(data, (t_rect){0, 0, 100, 100, RED_PIXEL});

    return (0);   if (key == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
}*/

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
                {
                    render_rect(data, (t_rect){xo, yo,
                    mapS, mapS, GREEN_PIXEL}, x, y);
                    //printf("printe q verde valor x %d, valor y %d, valor xo %d, valor yo %d", x , y, xo, yo);
                }
                else 
                {
			   		render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL}, x, y);
                    //printf("printe q vermelho");
                }
                /*else
                { 
                    //render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL});
                    mlx_pixel_put(data->mlx_ptr, data->win_ptr, 8,8, 0x8B0000);
                    printf("pixel");
                }*/
                x++;
            } 
            y++;
    } 
    return (0);
}
