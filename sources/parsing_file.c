/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:29:08 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/12 21:46:15 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_check_line(char *line, t_data *data, int y, int i)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == 'N' || line[x] == 'S' \
			|| line[x] == 'E' || line[x] == 'W')
		{
			player_info(data, x, y, line[x]);
			data->map.file[i][x] = '0';
			data->map.num_player++;
		}
		if (!ft_strchr("0 1NSWE", line[x]))
			ft_error("Error invalid character", data);
		x++;
	}
}

int	validate_color_2(char *line, int i)
{
	int		len;
	int		comma;

	comma = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0' && line[len] != ' ' && line[len] != '\t')
	{
		if (line[len] == ',')
			comma++;
		len++;
	}
	if (comma != 2)
	{
		printf("Error, color\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	validate_color(t_data *data, char *line, int i, int type)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	r = 0;
	g = 0;
	b = 0;
	if (validate_color_2(line, i) == 0)
	{
		colors = ft_split(line, ',');
		r = ft_atoi(colors[0]);
		g = ft_atoi(colors[1]);
		b = ft_atoi(colors[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		{
			printf("Error, one color\n");
			exit(EXIT_FAILURE);
		}
		if (type == 1)
			data->map.c = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		if (type == 2)
			data->map.f = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		free(colors);
	}
}

char	*validate_texture(char *line, int i)
{
	int		len;
	char	*textura;
	int		j;

	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0' && (line[len] != ' ' && line[len] != '\t'))
		len++;
	textura = malloc(sizeof(char) * (len - i + 1));
	if (!textura)
		return (NULL);
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' \
			&& line[i] != '\n')
		textura[j++] = line[i++];
	textura[j] = '\0';
	len = ft_strlen(textura);
	if (!ft_strnstr(&textura[len - 4], ".xpm", 4))
	{
		printf("Error, incorrect texture's path");
		exit(EXIT_FAILURE);
	}
	return (textura);
}

void	parsing_file(t_data *data, char *line, int row)
{
	int		i;

	(void)row;
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (ft_strncmp(line + i, "NO ", 3) == 0) 
		data->map.north = validate_texture(line, i + 3);
	else if (ft_strncmp(line + i, "SO ", 3) == 0) 
		data->map.south = validate_texture(line, i + 3);
	else if (ft_strncmp(line + i, "WE ", 3) == 0)
		data->map.west = validate_texture(line, i + 3);
	else if (ft_strncmp(line + i, "EA ", 3) == 0)
		data->map.east = validate_texture(line, i + 3);
	else if (ft_strncmp(line + i, "C ", 2) == 0)
		validate_color(data, line + i + 2, i + 2, 1);
	else if (ft_strncmp(line + i, "F ", 2) == 0)
		validate_color(data, line + i + 2, i + 2, 2);
	else if (line[i] == '0' || line[i] == '1')
		data->map.first_line = row;
	else if (line[i] != '\0')
	{
		printf("Error invalid line\n");
		exit (EXIT_FAILURE);
	}
}
