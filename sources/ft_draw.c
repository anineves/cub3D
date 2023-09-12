/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:27 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 23:05:20 by anaraujo         ###   ########.fr       */
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
	deltax /= pixels;
	deltay /= pixels;
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
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, \
							(WINDOW_HEIGHT - mapM * mapY) + i, rect.color);
		++i;
	}
	draw_line(data->mlx_ptr, data->win_ptr, rect.x, \
				(WINDOW_HEIGHT - mapM * mapY) + rect.y, \
				rect.x + rect.width, (WINDOW_HEIGHT - mapM * mapY) + rect.y, \
				0xFF8C00);
	draw_line(data->mlx_ptr, data->win_ptr, rect.x, \
				(WINDOW_HEIGHT - mapM * mapY) + rect.y, \
				rect.x, (WINDOW_HEIGHT - mapM * mapY) + rect.y + rect.height, \
				0xFF8C00);
	return (0);
}

void	draw_player(t_data *data, int x, int y)
{
	render_rect(data, (t_rect){((data->player.px * mapM) - 2), \
				((data->player.py * mapM) - 2), \
				4, 4, 0xFF0000}, x, y);
	draw_line(data->mlx_ptr, data->win_ptr, data->player.px * mapM, \
				(WINDOW_HEIGHT - mapM * mapY) + data->player.py * mapM, \
				data->player.px * mapM + data->player.dir_x * 8, \
				(WINDOW_HEIGHT - mapM * mapY) + data->player.py * mapM + \
				data->player.dir_y * 8, 0xFF8C00);
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
			xo = x * mapM;
			yo = y * mapM;
			if (data->map.full[y][x] == '1')
				render_rect(data, (t_rect){xo, yo, mapM, mapM, GREEN_PIXEL} \
					, x, y);
			else 
				render_rect(data, (t_rect){xo, yo, mapM, mapM, RED_PIXEL} \
					, x, y);
			draw_player(data, x, y);
		}
	}
	return (0);
}
