/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:41:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 19:45:51 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verific_args_ext(char *file, int argc)
{
	int	len;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(file);
	if (!ft_strnstr((file + len - 4), ".cub", 4))
	{
		printf("Error\nThe file must end in .cub.\n");
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
	ft_destroy_images(&data);
}
