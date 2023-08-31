/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:51:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/08/31 22:42:49 by anaraujo         ###   ########.fr       */
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

float px,py,pdx,pdy,pa;

int Buttons(int key, t_data *data)
{
    (void)data;
    if(key==97)
    { 
        pa+=5; 
        //pa=FixAng(pa); 
       // pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
    } 	
    if(key==100)
    { 
        pa-=5; 
        //pa=FixAng(pa);
        //pdx=cos(degToRad(pa)); 
        //pdy=-sin(degToRad(pa));
    } 
    if(key==119)
    { 
        px+=pdx*5; 
        py+=pdy*5;
    }
    if(key==115)
    { 
        px-=pdx*5; 
        py-=pdy*5;
    }
    if (key == XK_Escape)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL;
    }
    return(0);
}
