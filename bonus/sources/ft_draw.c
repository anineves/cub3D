/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:49:27 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/19 23:05:05 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_line(t_data *data, t_pos begin, t_pos end, int color)
{
	double	deltax;
	double	deltay;
	int		pixels;

	deltay = end.y - begin.y;
	deltax = end.x - begin.x;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, begin.x, begin.y, color);
		begin.x += deltax;
		begin.y += deltay;
		--pixels;
	}
}

int	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	if (data->win_ptr == NULL)
		return (1);
	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, j++, \
							(WINDOW_HEIGHT - MAPM * data->map.rows_full) \
							+ i, rect.color);
		++i;
	}
	draw_line(data, (t_pos){rect.x, \
				(WINDOW_HEIGHT - MAPM * data->map.rows_full) + rect.y}, \
				(t_pos){rect.x + rect.width, (WINDOW_HEIGHT - MAPM * \
				data->map.rows_full) + rect.y}, 0xFF8C00);
	draw_line(data, (t_pos){rect.x, \
				(WINDOW_HEIGHT - MAPM * data->map.rows_full) + rect.y}, \
				(t_pos){rect.x, (WINDOW_HEIGHT - MAPM * data->map.rows_full) + \
				rect.y + rect.height}, 0xFF8C00);
	return (0);
}

void	draw_player(t_data *data)
{
	render_rect(data, (t_rect){((data->player.px * MAPM) - 2), \
				((data->player.py * MAPM) - 2), \
				4, 4, 0xFF0000});
	draw_line(data, (t_pos){data->player.px * MAPM, \
				(WINDOW_HEIGHT - MAPM * data->map.rows_full) + \
				data->player.py * MAPM}, \
				(t_pos){data->player.px * MAPM + data->player.dir_x * 8, \
				(WINDOW_HEIGHT - MAPM * data->map.rows_full) + \
				data->player.py * MAPM + \
				data->player.dir_y * 8}, 0xFF8C00);
}

int	draw_map2d(t_data *data)
{
	int	x;
	int	y;
	int	xo;
	int	yo;

	y = 0;
	while (y < data->map.rows_full)
	{
		x = -1;
		while (++x < data->map.len)
		{
			xo = x * MAPM;
			yo = y * MAPM;
			if (data->map.full[y][x] == '1')
				render_rect(data, (t_rect){xo, yo, MAPM, MAPM, GREEN_PIXEL});
			else if (data->map.full[y][x] == '0')
				render_rect(data, (t_rect){xo, yo, MAPM, MAPM, RED_PIXEL});
			else
				render_rect(data, (t_rect){xo, yo, MAPM, MAPM, 0x000000});
			draw_player(data);
		}
		y++;
	}
	return (0);
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
