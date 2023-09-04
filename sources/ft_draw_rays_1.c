/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 11:47:24 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/03 15:46:01 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3d.h"

float	degToRad(int a) 
{
	return (a*M_PI/180.0);
}

int	FixAng(int a)
{
	if(a > 359)
	{
		a-=360;
	}
	if( a < 0)
	{
		a+=360;
	} 
	return (a);
}

float	distance(float ax, float ay, float bx, float by, float ang)
{
	return (cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay));
}

void draw_rays2d_1(t_data *data)
{
	int r,mx,my,mp,dof, pa; 
	float vx,vy,xo,yo;

	pa = 90;
	data->ray.ra = FixAng(pa);//ray set back 30 degrees
	for (r = 0; r < 20; r++)
	{
		//init_raycasting(&data->ray, &data->player);
		dof = 0;
		//side = 0;
		data->ray.sidedist_x = 100000;
		float Tan = tan(degToRad(data->ray.ra));
		if (cos(degToRad(data->ray.ra)) > 0.001)
		{
			data->ray.ray_x = (((int)data->player.px>>6)<<6)+64;
			data->ray.ray_y = (data->player.px - data->ray.ray_x)*Tan + data->player.py;
			xo = 64;
			yo = -xo * Tan;
		}//looking left
		else if (cos(degToRad(data->ray.ra)) < -0.001)
		{
			data->ray.ray_x=(((int)data->player.px>>6)<<6) -0.0001;
			data->ray.ray_y =(data->player.px - data->ray.ray_x) * Tan + data->player.py;
			xo = -64;
			yo = -xo * Tan;
		}//looking right
		else 
		{
			data->ray.ray_x = data->player.px; 
			data->ray.ray_y = data->player.py; 
			dof = 8;
		}//looking up or down. no hit  
		while ( dof < 8 )
		{ 
			mx = (int)(data->ray.ray_x)>>6;
			my = (int)(data->ray.ray_y )>>6;
			mp = my * mapX + mx;
			if(mp>0 && mp<mapX*mapY && data->map.full[my][mx]==1)
			{
				dof=8;
				data->ray.sidedist_x = cos(degToRad(data->ray.ra))*(data->ray.ray_x-data->player.px)-sin(degToRad(data->ray.ra))*(data->ray.ray_y -data->player.py);
			}//hit
			else
			{ 
				data->ray.ray_x += xo;
				data->ray.ray_y += yo;
				dof+=1;
			}//check next horizontal
		}
		//draw_line(data->mlx_ptr, data->win_ptr, data->player.px, data->player.py, data->ray.ray_x, data->ray.ray_y , 0xFFFFFF);
		vx=data->ray.ray_x; 
		vy=data->ray.ray_y ;

  //---Horizontal---
  		dof=0; 
		data->ray.sidedist_y=100000;
		Tan=1.0/Tan; 
		if(sin(degToRad(data->ray.ra))> 0.001)
		{ 
			data->ray.ray_y =(((int)data->player.py>>6)<<6) -0.0001; 
			data->ray.ray_x=(data->player.py-data->ray.ray_y )*Tan+data->player.px; 
			yo=-64; 
			xo=-yo*Tan;
		}//looking up 
		else if(sin(degToRad(data->ray.ra))<-0.001)
		{ 
			data->ray.ray_y =(((int)data->player.py>>6)<<6)+64;      
			data->ray.ray_x=(data->player.py - data->ray.ray_y )*Tan+data->player.px; 
			yo= 64; 
			xo=-yo*Tan;
		}//looking down
		else
		{ 
			data->ray.ray_x = data->player.px; 
			data->ray.ray_y = data->player.py; 
			dof=8;
		}                                                   //looking straight left or right
		while(dof < 8) 
		{ 
			mx=(int)(data->ray.ray_x)>>6; 
			my=(int)(data->ray.ray_y )>>6; 
			mp=my*mapX+mx;                          
			if(mp>0 && mp<mapX*mapY && data->map.full[my][mx]==1)
			{ 
				dof=8; 
				data->ray.sidedist_y=cos(degToRad(data->ray.ra))*(data->ray.ray_x-data->player.px)-sin(degToRad(data->ray.ra))*(data->ray.ray_y - data->player.py);
			}//hit         
			else
			{ 
				data->ray.ray_x += xo; 
				data->ray.ray_y += yo; 
				dof+=1;
			}//check next horizontal
		}
		if(data->ray.sidedist_x < data->ray.sidedist_y)
		{ 
			data->ray.ray_x = vx;
			data->ray.ray_y = vy;
			data->ray.sidedist_y = data->ray.sidedist_x;
		}                  //horizontal hit first
		draw_line(data->mlx_ptr, data->win_ptr, data->player.px, data->player.py, data->ray.ray_x, data->ray.ray_y , 0xFF8C00);
		//draw_line(data->mlx_ptr, data->win_ptr, data->player.px, data->player.py, data->ray.sidedist_x, data->ray.sidedist_y , 0xFFFFFF);
		int ca=FixAng(pa-data->ray.ra); 
		data->ray.sidedist_y=data->ray.sidedist_y*cos(degToRad(ca));                            //fix fisheye 
		int lineH = (mapS*320)/(data->ray.sidedist_y); 
		if(lineH > 320)
		{ 
			lineH = 320;
		}                     //line height and limit
		//int lineOff = 160 - (lineH>>1);                                               //line offset
  
		//glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  

		data->ray.ra=FixAng(data->ray.ra-1);                                                              //go to next ray
	}
}
