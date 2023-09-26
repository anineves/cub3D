/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:29:08 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/26 18:21:01 by asousa-n         ###   ########.fr       */
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
			ft_error("Error invalid character", data, 1);
		x++;
	}
}

int	validate_color_2(t_data *data, char *line, int i)
{
	int		len;
	int		comma;

	comma = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0')
	{
		if (!ft_strchr("0123456789 ,", line[len]))
			ft_error("Invalid character in color", data, 1);
		if (line[len] == ',' && line[len + 1])
		{
			if (line[len + 1] == ',')
				ft_error("Duplicate comma", data, 1);
			comma++;
		}
		len++;
	}
	if (comma != 2)
		ft_error("Missing a color\n", data, 1);
	return (0);
}

void	validate_color(t_data *data, char *line, int i, int type)
{
	int		r;
	int		g;
	int		b;
	char	**colors;

	r = -1;
	g = -1;
	b = -1;
	if (validate_color_2(data, &line[i], 0) == 0)
	{
		colors = ft_split(line, ',');
		ft_color_empty(colors, data);
		r = ft_atoi(colors[0]);
		g = ft_atoi(colors[1]);
		b = ft_atoi(colors[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			ft_error("Wrong value\n", data, 1);
		if (type == 1)
			data->map.c = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		if (type == 2)
			data->map.f = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		ft_free_map(colors);
	}
}

void	validate_texture1(t_data *data, char *textura)
{
	int	len;
	int	fd;

	len = ft_strlen(textura);
	if (!ft_strnstr(&textura[len - 4], ".xpm", 4))
	{
		free(textura);
		ft_error("Incorrect texture's path", data, 1);
	}
	fd = open(textura, O_RDONLY);
	if (fd == -1)
	{
		free(textura);
		ft_error("Cannot open the xpm\n", data, 1);
	}
}

char	*validate_texture(t_data *data, char *line, int i)
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
	validate_texture1(data, textura);
	return (textura);
}
