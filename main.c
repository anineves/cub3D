#include "cub3d.h"

void verific_args_ext(char *file, int argc)
{
    int len;
    len = ft_strlen(file);
    if(argc != 2)
    {
        printf("Error, invalid number of arguments");
        exit(EXIT_FAILURE);
    }
    if(!ft_strnstr((file + len - 4), ".cub", 4))
    {
        printf("The file must end in .cub\n");
        exit(EXIT_FAILURE);
    }

}

int	main(int argc, char **argv)
{
    t_data	*data;

    verific_args_ext(argv[1], argc);
    data = malloc(sizeof(t_data));
    init_data(data);
    init_mlx(data);
    ft_read_file(data, argv[1]);
    //parsing_file(&data, argv[1];
    init_player_direction(data);
    draw_map2d(data);
    listen(data);
    //mlx_hook(data->win_ptr, 02, (1L << 0), &r, data);
    //mlx_hook(data->win_ptr, 12, (1L << 15), &draw_map2d, data);
    //mlx_hook(data.win_ptr, 12, (1L << 15), &draw_rays2d, &data);
    mlx_loop_hook(data->mlx_ptr, &render_mini, data);
    //mlx_loop_hook(data.mlx_ptr, &draw_rays2d_1, &data);
    mlx_loop(data->mlx_ptr);
    /* we will exit the loop if there's no window left, and execute this code */
    //mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
}
