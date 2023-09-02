/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_buttons.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/02 09:43:50 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int FixAng(int a)
{ 
    if(a>359)
    { 
        a-=360;
    } 
    if(a<0)
    { 
        a+=360;
    } 
    return a;
}

int not_hit_wall(double x, double y)
{
    
}

int Buttons(int key, t_data *data)
{
    double new_x;
    double new_y;

    if(key==97)
    { 
        new_x = data->player->px - 1;
        new_y = data->player->py;
        //pa=FixAng(pa); 
       // pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
        return(not_hit_wall(new_x, new_y))
    } 	
    if(key==100)
    { 
        px+=1; 
        //pa=FixAng(pa);
        //pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
    } 
    if(key==119)
    { 
        py-=1;
        //px+=pdx*5; 
        //py+=pdy*5;
    }
    if(key==115)
    { 
        py+=1;
        //px-=pdx*5; 
        //py-=pdy*5;
    }
    if (key == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return(0);
}



