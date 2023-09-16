/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 21:43:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 11:31:56 by asousa-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	if (!s1)
	{
		return (NULL);
	}
	newstr = (char *)malloc (sizeof(char) * \
	(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newstr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		newstr[j++] = s1[i];
	i = -1;
	while (s2[++i])
		newstr[j++] = s2[i];
	newstr[j] = '\0';
	free(s1);
	return (newstr);
}


void	ft_free_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i += 1;
	}
	free(map);
	map = NULL;
}

void	ft_free_textures1(int **textures)
{
	size_t	i;

	i = 0;
	while (textures[i])
	{
		free(textures[i]);
		i++;
	}
	if (textures)
	{
		free(textures);
		textures = NULL;
	}
}

void ft_free_textures3(t_data *data)
{
	int i;

	i = 0;
    while(i < 4)
    {
        if (data->textures[i] != NULL)
        {
            free(data->textures[i]);
            data->textures[i] = NULL;
        }
		i++;
    }
    free(data->textures);
    data->textures = NULL;
}


void	ft_free_textures(t_data *data)
{
	if (data->map.north)
		free(data->map.north);
	if (data->map.south)
		free(data->map.south);
	if (data->map.east)
		free(data->map.east);
	if (data->map.west)
		free(data->map.west);
}

void ft_destroy_images(t_data *data)
{
	if (data->north_img.img)
		mlx_destroy_image(data->mlx_ptr, data->north_img.img);
	if (data->south_img.img)
		mlx_destroy_image(data->mlx_ptr, data->south_img.img);
	if (data->west_img.img)
		mlx_destroy_image(data->mlx_ptr, data->west_img.img);
	if (data->east_img.img)
		mlx_destroy_image(data->mlx_ptr, data->east_img.img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}

void	ft_error(char *msg, t_data *data, int code)
{
	if (!data)
		exit(code);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		//mlx_loop_end(data->mlx_ptr); //testar
		free(data->mlx_ptr);
	}
	if(data->map.file)
		ft_free_map(data->map.file);
	if(data->map.full)
		ft_free_map(data->map.full);
	if (data->textures)
		ft_free_textures3(data);
	ft_free_textures(data);
	if(code == 1)
		ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putendl_fd(msg, STDOUT_FILENO);
	exit(code);
}