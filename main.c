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
    t_data	data;

    verific_args_ext(argv[1], argc);
    init_data(&data);
    get_file(&data, argv[1]);
    init_player_direction(&data);
    init_mlx(&data);
    init_textures(&data);
    render_images(&data);
    events(&data);
    mlx_loop_hook(data.mlx_ptr, &render, &data);
    mlx_loop(data.mlx_ptr);
}
