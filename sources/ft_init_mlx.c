/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:31:02 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/01 21:32:11 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
    if (data->mlx_ptr == NULL)
        return (MLX_ERROR);
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
                                "my window");
    if (data->win_ptr == NULL)
    {
        free(data->win_ptr);
        return (MLX_ERROR);
    }
}