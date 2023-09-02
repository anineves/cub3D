/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:03:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/02 18:46:57 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float degToRad(int a) 
{ 
	return a*M_PI/180.0;
}

int FixAng(int a)
{ 
	if(a > 359)
	{
		a-=360;
	}
	if( a < 0)
	{
		a+=360;
	} 
	return a;
}

float distance(float ax, float ay, float bx, float by, float ang)
{ 
	return cos(degToRad(ang))*(bx-ax)-sin(degToRad(ang))*(by-ay);
}

void drawRays2D(t_data *data)
{
	int r,mx,my,mp,dof,side, pa; 
	float vx,vy,ra,xo,yo,disV,disH; 
 
	pa = 0;
	data->ray.ra = FixAng(pa + 30);               //ray set back 30 degrees
 
	for (r = 0; r < 60; r++)
	{
  //---Vertical--- 
		dof = 0;
		side = 0;
		disV = 100000;
		float Tan = tan(degToRad(ra));
		if (cos(degToRad(ra))> 0.001)
		{ 
			data->ray.ray_x = (((int)data->player.px>>6)<<6)+64;      
			data->ray.ray_y = (data->player.px - data->ray.ray_x)*Tan + data->player.py; 
			xo= 64; 
			yo=-xo*Tan;
		}//looking left
		else if(cos(degToRad(ra))<-0.001)
		{ 
			data->ray.ray_x=(((int)data->player.px>>6)<<6) -0.0001; 
			data->ray.ray_y =(data->player.px - data->ray.ray_x)*Tan + data->player.py; 
			xo=-64; 
			yo=-xo*Tan;
		}//looking right
		else 
		{ 
			data->ray.ray_x = data->player.px; 
			data->ray.ray_y = data->player.py; 
			dof=8;
		}//looking up or down. no hit  
		while ( dof < 8 )
		{ 
			mx = (int)(data->ray.ray_x)>>6;
			my = (int)(data->ray.ray_y )>>6;
			mp = my*mapX+mx;
			if(mp>0 && mp<mapX*mapY && data->map.full[my][mx]==1)
			{ 
				dof=8;
				disV=cos(degToRad(ra))*(data->ray.ray_x-data->player.px)-sin(degToRad(ra))*(data->ray.ray_y -data->player.py);
			}//hit         
			else
			{ 
				data->ray.ray_x += xo; 
				data->ray.ray_y += yo; 
				dof+=1;
			}                                               //check next horizontal
		}   
		vx=data->ray.ray_x; 
		vy=data->ray.ray_y ;

  //---Horizontal---
  		dof=0; 
		disH=100000;
		Tan=1.0/Tan; 
		if(sin(degToRad(ra))> 0.001)
		{ 
			data->ray.ray_y =(((int)data->player.py>>6)<<6) -0.0001; 
			data->ray.ray_x=(data->player.py-data->ray.ray_y )*Tan+data->player.px; 
			yo=-64; 
			xo=-yo*Tan;
		}//looking up 
		else if(sin(degToRad(ra))<-0.001)
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
				disH=cos(degToRad(ra))*(data->ray.ray_x-data->player.px)-sin(degToRad(ra))*(data->ray.ray_y - data->player.py);
			}//hit         
			else
			{ 
				data->ray.ray_x += xo; 
				data->ray.ray_y += yo; 
				dof+=1;
			}                                               //check next horizontal
		}
		if(disV < disH)
		{ 
			data->ray.ray_x = vx; 
			data->ray.ray_y = vy;
			disH = disV;
		}                  //horizontal hit first
		draw_line(data->mlx_ptr, data->win_ptr, data->player.px, data->player.py, data->ray.ray_x, data->ray.ray_y , 0xFF8C00);
		int ca=FixAng(pa-ra); 
		disH=disH*cos(degToRad(ca));                            //fix fisheye 
		int lineH = (mapS*320)/(disH); 
		if(lineH > 320)
		{ 
			lineH = 320;
		}                     //line height and limit
		//int lineOff = 160 - (lineH>>1);                                               //line offset
  
		//glLineWidth(8);glBegin(GL_LINES);glVertex2i(r*8+530,lineOff);glVertex2i(r*8+530,lineOff+lineH);glEnd();//draw vertical wall  

		ra=FixAng(ra-1);                                                              //go to next ray
	}
}//-----------------------------------------------------------------------------
