/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:19:21 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 19:10:39 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	count_lines(t_data *data, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error("Cannot open the file\n", data, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map.rows++;
		free(line);
	}
	close(fd);
}

int	all_params(t_data *data)
{
	if (data->map.n != 1 || data->map.s != 1 || data->map.w != 1 \
			|| data->map.e != 1 || data->map.f_c != 1 \
			|| data->map.f_f != 1 || data->map.first_line == 0)
		ft_error("param", data, 1); 
	return (1);
}

int	ft_fill_path(char *line, int i, t_data *data)
{
	if (ft_strncmp(line + i, "NO ", 3) == 0 && data->map.n == 0)
	{
		data->map.north = validate_texture(data, line, i + 3);
		data->map.n++;
		return (1);
	}
	else if (ft_strncmp(line + i, "SO ", 3) == 0 && data->map.s == 0)
	{
		data->map.south = validate_texture(data, line, i + 3);
		data->map.s++;
		return (1);
	}
	else if (ft_strncmp(line + i, "WE ", 3) == 0 && data->map.w == 0)
	{
		data->map.west = validate_texture(data, line, i + 3);
		data->map.w++;
		return (1);
	}
	else if (ft_strncmp(line + i, "EA ", 3) == 0 && data->map.e == 0)
	{
		data->map.east = validate_texture(data, line, i + 3);
		data->map.e++;
		return (1);
	}
	return (0);
}

int	parsing_file(t_data *data, char *line, int row)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_fill_path(line, i, data))
		return (1);
	else if (ft_strncmp(line + i, "C ", 2) == 0 && data->map.f_c == 0)
	{
		validate_color(data, line, i + 2, 1);
		data->map.f_c++;
		return (1);
	}
	else if (ft_strncmp(line + i, "F ", 2) == 0 && data->map.f_f == 0)
	{
		validate_color(data, line, i + 2, 1);
		data->map.f_f++;
		return (1);
	}
	else if (line[i] == '0' || line[i] == '1')
		data->map.first_line = row;
	else if (line[i] != '\0')
		ft_error("Invalid line\n", data, 1);
	return (0);
}
