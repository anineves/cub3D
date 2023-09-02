#include "cub3d.h"

/*int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,2,1,
 1,1,1,1,1,1,1,1,	
};*/

/*float degToRad(int a) 
{ 
    return a*PI/180.0;
}*/


int	main(void)
{
    t_data	data;

    init_data(&data);
    init_mlx(&data);
    /* Setup hooks */ 
    ft_read_map(&data, "1.cub");
    init_player_direction(&data);
    mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &Buttons, &data);

    mlx_loop_hook(data.mlx_ptr, &drawMap2D, &data);
    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}
