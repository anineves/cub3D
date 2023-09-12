
#include "../cub3d.h"


void	dda(t_ray *ray, t_player *player)
{
	
	printf(" dirx %f\n diry %f\n", ray->dir_x, ray->dir_y);
	if (ray->dir_x < 0) 
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->px - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0f - player->px) * ray->deltadist_x;
	}
	if (ray->dir_y > 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->py - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0f - player->py) * ray->deltadist_y;
	}
	printf("primeira vex \n\n\n");
		printf("Entrei , sidex %f \n", ray->sidedist_x);
		printf("Entrei , sidey %f \n\n", ray->sidedist_y);
}

void	apply_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		printf("Entrei , sidex %f \n", ray->sidedist_x);
		printf("Entrei , sidey %f \n", ray->sidedist_y);
	
	 	if (data->map.full[ray->map_y][ray->map_x] == '1')
		{
			hit = 1;
		}

	}
}