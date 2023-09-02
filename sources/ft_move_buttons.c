/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/02 18:44:00 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int not_hit_wall(t_data *data, double x, double y)
{
    (void)data;
    (void)x;
    (void)y;
    return (0);
}

int Buttons(int key, t_data *data)
{
    //double new_x;
    //double new_y;

    if(key==97)
    { 
        printf("entrei no 97 %f %f\n", data->player.px, data->player.py );
        data->player.px = data->player.px + data->player.dir_x * MOVESPEED;
        data->player.py= data->player.py - data->player.dir_y * MOVESPEED;
        printf("entrei no 97 posicao x: %f posicao y:%f dir_x:%f dir_y:%f\n", data->player.px, data->player.py, data->player.dir_x, data->player.dir_y);
        //pa=FixAng(pa); 
       // pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
        //return(not_hit_wall(data, new_x, new_y));
    } 	
    if(key==100)
    { 
        data->player.px = data->player.px - data->player.dir_x * MOVESPEED;
        data->player.py = data->player.py + data->player.dir_y * MOVESPEED;
        //return(not_hit_wall(data, new_x, new_y));
        //pa=FixAng(pa);
        //pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
        printf("entrei no 100 %f %f\n", data->player.px, data->player.py );
    } 
    if(key==119)
    { 
        data->player.px = data->player.px + data->player.dir_x * MOVESPEED;
        data->player.py = data->player.py + data->player.dir_y * MOVESPEED;
        //return(not_hit_wall(data, new_x, new_y));
        //py-=1;
        //px+=pdx*5; 
        //py+=pdy*5;
        printf("entrei no 119 %f %f\n", data->player.px, data->player.py );
    }
    if(key==115)
    { 
        //py+=1;
        data->player.px = data->player.px - data->player.dir_x * MOVESPEED;
        data->player.py = data->player.py - data->player.dir_y * MOVESPEED;
        //return(not_hit_wall(data, new_x, new_y));
        //px-=pdx*5; 
        //py-=pdy*5;
        printf("entrei no 115 %f %f\n", data->player.px, data->player.py );
    }
    if (key == XK_Right)
    {
        double oldDirX = data->player.dir_x;
        data->player.dir_x  = (data->player.dir_x  * cos(-rotSpeed)) - (data->player.dir_y * sin(-rotSpeed));
        data->player.dir_y = oldDirX * sin(-rotSpeed) + data->player.dir_y * cos(-rotSpeed);
        double oldPlaneX = data->player.plane_x;
        data->player.plane_x = data->player.plane_x * cos(-rotSpeed) - data->player.plane_y * sin(-rotSpeed);
        data->player.plane_y = oldPlaneX * sin(-rotSpeed) + data->player.plane_y * cos(-rotSpeed);
    }
    if (key == XK_Left )
    {
        double oldDirX = data->player.dir_x;
        data->player.dir_x = data->player.dir_x * cos(rotSpeed) - data->player.dir_y * sin(rotSpeed);
        data->player.dir_y = oldDirX * sin(rotSpeed) + data->player.dir_y * cos(rotSpeed);
        double oldPlaneX = data->player.plane_x;
        data->player.plane_x = data->player.plane_x * cos(rotSpeed) - data->player.plane_y * sin(rotSpeed);
        data->player.plane_y = oldPlaneX * sin(rotSpeed) + data->player.plane_y * cos(rotSpeed);
    }
    if (key == XK_Escape)
    {
        printf("entrei no Escape");
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
        return(1);
    }
    return(0);
}



