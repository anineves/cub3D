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


int	main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("wrong ");
        return(1);
    }
    t_data	data;

    init_data(&data);
    init_mlx(&data);
    
    /* Setup hooks */ 
    ft_read_file(&data, argv[1]);
    
    init_player_direction(&data);
    draw_map2d(&data);
    mlx_hook(data.win_ptr, 02, (1L << 0), &buttons, &data);
    mlx_hook(data.win_ptr, 12, (1L << 15), &draw_map2d, &data);
    //mlx_hook(data.win_ptr, 12, (1L << 15), &draw_rays2d, &data);
    mlx_loop_hook(data.mlx_ptr, &draw_map2d, &data);
    //mlx_loop_hook(data.mlx_ptr, &draw_rays2d_1, &data);
    mlx_loop(data.mlx_ptr);

    /* we will exit the loop if there's no window left, and execute this code */
    mlx_destroy_display(data.mlx_ptr);
    free(data.mlx_ptr);
}
