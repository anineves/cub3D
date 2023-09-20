/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:13:04 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/20 19:09:12 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_destroy_images(t_data *data)
{
	if (data->north_img.img)
		mlx_destroy_image(data->mlx_ptr, data->north_img.img);
	if (data->south_img.img)
		mlx_destroy_image(data->mlx_ptr, data->south_img.img);
	if (data->west_img.img)
		mlx_destroy_image(data->mlx_ptr, data->west_img.img);
	if (data->east_img.img)
		mlx_destroy_image(data->mlx_ptr, data->east_img.img);
	if (data->menu.button_p.img)
	{
		free(data->menu.button_p.img);
		mlx_destroy_image(data->mlx_ptr, data->menu.button_p.img);
	}
	if (data->menu.button_q.img)
	{
		free(data->menu.button_q.img);	
		mlx_destroy_image(data->mlx_ptr, data->menu.button_q.img);
	}
	if (data->menu.background.img)
	{
		free(data->menu.background.img);
		mlx_destroy_image(data->mlx_ptr, data->menu.background.img);
	}
	if (data->coin_img.img)
		mlx_destroy_image(data->mlx_ptr, data->coin_img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	ft_error(char *msg, t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	if (data->map.file)
		ft_free_map(data->map.file);
	if (data->map.full)
		ft_free_map(data->map.full);
	if (data->textures)
		ft_free_textures3(data);
	ft_free_textures(data);
	if (code == 1)
		ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(code);
}

int	ft_close(t_data *data)
{
	ft_error("CLOSED", data, 0);
	return (0);
}
