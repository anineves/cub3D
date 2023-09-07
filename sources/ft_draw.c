/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:27 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/06 23:11:31 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltay = endY - beginY;
	deltax = endX - beginX;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels; // 1
	deltay /= pixels; // 0
	pixelx = beginX;
	pixely = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
}


int	render_rect(t_data *data, t_rect rect, int x, int y)
{
	int	i;
	int	j;

	(void)x;
	(void)y;
	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, (WINDOW_HEIGHT - mapS*mapY ) + i, rect.color);
		++i;
	}
	draw_line(data->mlx_ptr, data->win_ptr, rect.x, (WINDOW_HEIGHT - mapS*mapY ) + rect.y, \
			 rect.x + rect.width, (WINDOW_HEIGHT - mapS*mapY ) + rect.y, 0xFF8C00);
	draw_line(data->mlx_ptr, data->win_ptr, rect.x, (WINDOW_HEIGHT - mapS*mapY ) + rect.y, \
			 rect.x, (WINDOW_HEIGHT - mapS*mapY ) + rect.y + rect.height, 0xFF8C00);
	return (0);
}

int	draw_map2d(t_data *data)
{
	int	x;
	int	y;
	int	xo;
	int	yo;

	y = -1;
	while (++y < mapY)
	{
		x = -1;
		while (++x < mapX)
		{
			xo = x * mapS;
			yo = y * mapS;
			//printf("linha %s",data->map.file[y] );
			if (data->map.full[y][x] == '1')
			{
				//printf("valor x %d, valor y %d\n", x , y);
				render_rect(data, (t_rect){xo, yo, mapS, mapS, GREEN_PIXEL} \
					, x, y);
			}
			else 
				render_rect(data, (t_rect){xo, yo, mapS, mapS, RED_PIXEL} \
					, x, y);
			render_rect(data, (t_rect){((data->player.px) - 2),((data->player.py) - 2), \
					4, 4, 0xFF0000}, x, y);
			draw_line(data->mlx_ptr, data->win_ptr, data->player.px, \
						(WINDOW_HEIGHT - mapS*mapY ) + data->player.py, data->player.px + data->player.dir_x * 4,\
						(WINDOW_HEIGHT - mapS*mapY ) + data->player.py + data->player.dir_y * 4, 0xFF8C00);
		}
	}
	draw_rays2d(data);
    //draw_rays2d_1(data);
	return (0);
}
