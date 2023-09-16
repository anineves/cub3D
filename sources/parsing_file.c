/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-n <asousa-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 20:29:08 by anaraujo          #+#    #+#             */
/*   Updated: 2023/09/16 11:44:00 by asousa-n         ###   ########.fr       */
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
	printf(" i %d, len %d\n", i, len);
	while (line[len] != '\0')
	{
		printf("entrei %c \n", line[len]);
		if (!ft_strchr("0123456789 ,", line[len]))
			ft_error("Error invalid character in color", data, 1);
		if (line[len] == ',' && line[len + 1])
			comma++;
		len++;
	}
	printf("coma%d\n", comma);
	if (comma != 2)
		ft_error(" missing One color\n", data,1);
	return (0);
}

void	validate_color(t_data *data, char *line, int i, int type)
{
	int		r;
	int		g;
	int		b;
	int		j;
	char	**colors;

	r = -1;
	g = -1;
	b = -1;
	j = -1;
	if (validate_color_2(data, line, i) == 0)
	{
		colors = ft_split(line, ',');
		r = ft_atoi(colors[0]);
		g = ft_atoi(colors[1]);
		b = ft_atoi(colors[2]);
		if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
			ft_error("One color\n", data, 1);
		if (type == 1)
			data->map.c = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		if (type == 2)
			data->map.f = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
		while (colors[++j])
                free(colors[j]);
            free(colors);
	}
}

char	*validate_texture(t_data *data, char *line, int i)
{
	int		len;
	char	*textura;
	int		j;
	int		fd;

	j = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	len = i;
	while (line[len] != '\0' && (line[len] != ' ' && line[len] != '\t'))
		len++;
	textura = malloc(sizeof(char) * (len - i + 1)); //temos de libertar isto
	if (!textura)
		return (NULL);
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\t' \
			&& line[i] != '\n')
		textura[j++] = line[i++];
	textura[j] = '\0';
	len = ft_strlen(textura);
	if (!ft_strnstr(&textura[len - 4], ".xpm", 4))
	{
		free(textura);
		ft_error("incorrect texture's path", data, 1);
	}
	fd = open(textura, O_RDONLY);
	if (fd == -1)
	{
		free(textura);
		ft_error("Cannot open the xpm\n", data, 1);
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
	if (ft_strncmp(line + i, "NO ", 3) == 0 && data->map.n == 0)
	{
		data->map.north = validate_texture(data, line, i + 3 );
		data->map.n++;
	}
	else if (ft_strncmp(line + i, "SO ", 3) == 0 && data->map.s == 0)
	{
		
		data->map.south = validate_texture(data, line, i + 3);
		data->map.s++;
	} 
	else if (ft_strncmp(line + i, "WE ", 3) == 0 && data->map.w == 0)
	{
		
		data->map.west = validate_texture(data, line, i + 3);
		data->map.w++;
	}
	else if (ft_strncmp(line + i, "EA ", 3) == 0 && data->map.e == 0)
	{
		data->map.east = validate_texture(data, line, i + 3);
		data->map.e++;
	}
	else if (ft_strncmp(line + i, "C ", 2) == 0 && data->map.f_c == 0)
	{	
		validate_color(data, line, i + 2, 1);
		data->map.f_c++;
	}
	else if (ft_strncmp(line + i, "F ", 2) == 0 && data->map.f_f == 0)
	{	
		validate_color(data, line, i + 2, 1);
		data->map.f_f++;
	}
	else if (line[i] == '0' || line[i] == '1')
		data->map.first_line = row;
	else if (line[i] != '\0')
		ft_error("Invalid line\n", data, 1);
	printf("ceiling %x\n", data->map.c);
}
