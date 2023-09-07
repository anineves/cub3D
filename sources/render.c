/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:38:30 by asousa-n          #+#    #+#             */
/*   Updated: 2023/09/07 23:06:23 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int render_mini(t_data *data)
{
    buttons(data);
    if(data->player.has_moved == 0)
        return (0);
    draw_map2d(data);
    return(0);
}